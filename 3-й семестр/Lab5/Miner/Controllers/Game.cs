using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;

namespace Lab5
{

    public class Game
    {
        public static readonly int[] mapSize = {8, 16, 24};
        public const int cellSize = 40;
        
        public static int n;

        private static int currentPictureToSet = 0;

        public static int[,] map;

        public static int[,] bombFlag;

        public static Button[,] buttons;

        public static Image spriteSet;

        private static bool isFirstStep;

        private static Point firstCoord;

        public static Form form;

        private static System.Media.SoundPlayer player = new System.Media.SoundPlayer(@"C:\My files\Вуз\Программирование\2 семестр\Programming\3-й семестр\Lab5\Miner\music.wav");

        private static System.Media.SoundPlayer bombsound = new System.Media.SoundPlayer(@"C:\My files\Вуз\Программирование\2 семестр\Programming\3-й семестр\Lab5\Miner\boom.wav");

       
        private static void ConfigureMapSize(Form current, int n)
        {
            current.Width = mapSize[n] * cellSize + 20;
            current.Height = (mapSize[n] + 1) * cellSize;
        }

        private static void InitMap(int n)
        {
            for (int i = 0; i < mapSize[n]; i++)
            {
                for (int j = 0; j < mapSize[n]; j++)
                {
                    map[i, j] = 0;
                    bombFlag[i, j] = 0;
                }
            }
        }

        public static void Init(Form current)
        {
            
            form = current;
            map = new int[mapSize[n], mapSize[n]];
            buttons = new Button[mapSize[n], mapSize[n]];
            bombFlag = new int[mapSize[n], mapSize[n]];
            currentPictureToSet = 0;
            isFirstStep = true;
            spriteSet = new Bitmap(Path.Combine(new DirectoryInfo(Directory.GetCurrentDirectory()).Parent.Parent.FullName.ToString(), "Sprites\\tiles.png"));
            ConfigureMapSize(current, n);
            InitMap(n);
            InitButtons(current, n);
        }

        private static void InitButtons(Form current, int n)
        {
            for (int i = 0; i < mapSize[n]; i++)
            {
                for (int j = 0; j < mapSize[n]; j++)
                {
                    Button button = new Button();
                    button.Location = new Point(j * cellSize, i * cellSize);
                    button.Size = new Size(cellSize, cellSize);
                    button.Image = FindNeededImage(0, 0);
                    button.MouseUp += new MouseEventHandler(OnButtonPressedMouse);
                    current.Controls.Add(button);
                    buttons[i, j] = button;
                }
            }
        }

        private static void OnButtonPressedMouse(object sender, MouseEventArgs e)
        {
            Button pressedButton = sender as Button;
            switch (e.Button.ToString())
            {
                case "Right":
                    OnRightButtonPressed(pressedButton);
                    break;
                case "Left":
                    OnLeftButtonPressed(pressedButton);
                    break;
            }
        }

        private static void OnRightButtonPressed(Button pressedButton)
        {
            currentPictureToSet++;
            currentPictureToSet %= 2;
            int posX = 0;
            int posY = 0;

            int iButton = pressedButton.Location.Y / cellSize;
            int jButton = pressedButton.Location.X / cellSize;
            

            switch (currentPictureToSet)
            {
                case 0:
                    posX = 0;
                    posY = 0;
                    bombFlag[iButton, jButton] = 0;
                    
                    isWin(isFirstStep);
                    break;
                case 1:
                    posX = 0;
                    posY = 2;
                    bombFlag[iButton, jButton] = 1;
                    
                    isWin(isFirstStep);
                    break;
            }
            pressedButton.Image = FindNeededImage(posX, posY);
        }

        private static void isWin(bool isFirst)
        {
            int bomb = 0;
            int findbomb = 0;
            if (isFirst == false)
            {
                for (int i = 0; i < mapSize[n]; i++)
                {
                    for (int j = 0; j < mapSize[n]; j++)
                    {
                        if (map[i, j] == -1)
                        {
                            bomb++;
                            if (bombFlag[i, j] == 1)
                            {
                                findbomb++;
                            }
                        }
                    }
                }
                if (bomb == findbomb)
                {
                    MessageBox.Show("Победа!");
                    form.Controls.Clear();
                    Init(form);
                }
            }
            else
            {
                
                MessageBox.Show("Бомб не обнаруженно");
                form.Controls.Clear();
                Init(form);
            }
        }


        private static void OnLeftButtonPressed(Button pressedButton)
        {
            pressedButton.Enabled = false;
            int iButton = pressedButton.Location.Y / cellSize;
            int jButton = pressedButton.Location.X / cellSize;
            if (isFirstStep)
            {
                firstCoord = new Point(jButton,iButton);
                SeedMap(n);
                CountCellBomb(n);               
                isFirstStep = false;
            }
            OpenCells(iButton, jButton);

            if (map[iButton, jButton] == -1)
            {

                ShowAllBombs(iButton,jButton, n);
                bombsound.Load();
                bombsound.Play();
                MessageBox.Show("Поражение!");
                form.Controls.Clear();
                Init(form);
            }
        }

        private static void ShowAllBombs(int iBomb,int jBomb, int n)
        {
            for (int i = 0; i < mapSize[n]; i++)
            {
                for (int j = 0; j < mapSize[n]; j++)
                {
                    if (i == iBomb && j == jBomb)
                        continue;
                    if(map[i, j] == -1)
                    {
                        buttons[i, j].Image = FindNeededImage(3, 2);
                    }
                }
            }
        }

        public static Image FindNeededImage(int xPos,int yPos)
        {
            Image image = new Bitmap(cellSize, cellSize);
            Graphics g = Graphics.FromImage(image);
            g.DrawImage(spriteSet, new Rectangle(new Point(0, 0), new Size(cellSize, cellSize)), 0 + 32 * xPos, 0 + 32* yPos,33,33,GraphicsUnit.Pixel);


            return image;
        }

        private static void SeedMap(int n)
        {
            Random r = new Random();
            int number = r.Next(mapSize[n] , (mapSize[n]* mapSize[n])/2);
            MessageBox.Show("На поле обнаруженно " + number.ToString()+ " бомб");
            for (int i = 0; i < number; i++)
            {
                int posI = r.Next(0, mapSize[n] - 1);
                int posJ = r.Next(0, mapSize[n] - 1);

                while (map[posI, posJ] == -1 || (Math.Abs(posI-firstCoord.Y)<=1 && Math.Abs(posJ - firstCoord.X) <= 1))
                {
                    posI = r.Next(0, mapSize[n] - 1);
                    posJ = r.Next(0, mapSize[n] - 1);
                }
                map[posI, posJ] = -1;
            }
        }

        private static void CountCellBomb(int n)
        {
            for(int i = 0; i < mapSize[n]; i++)
            {
                for(int j = 0; j < mapSize[n]; j++)
                {
                    if (map[i, j] == -1)
                    {
                        for(int k = i - 1; k < i + 2; k++)
                        {
                            for(int l = j - 1; l < j + 2; l++)
                            {
                                if (!IsInBorder(k, l, n) || map[k, l] == -1)
                                    continue;
                                map[k, l] = map[k, l] + 1;
                            }
                        }
                    }
                }
            }
        }

        private static void OpenCell(int i,int j)
        {
            buttons[i, j].Enabled = false;

            switch (map[i, j])
            {
                case 1:
                    buttons[i, j].Image = FindNeededImage(1, 0);
                    break;
                case 2:
                    buttons[i, j].Image = FindNeededImage(2, 0);
                    break;
                case 3:
                    buttons[i, j].Image = FindNeededImage(3, 0);
                    break;
                case 4:
                    buttons[i, j].Image = FindNeededImage(4, 0);
                    break;
                case 5:
                    buttons[i, j].Image = FindNeededImage(0, 1);
                    break;
                case 6:
                    buttons[i, j].Image = FindNeededImage(1, 1);
                    break;
                case 7:
                    buttons[i, j].Image = FindNeededImage(2, 1);
                    break;
                case 8:
                    buttons[i, j].Image = FindNeededImage(3, 1);
                    break;
                case -1:
                    buttons[i, j].Image = FindNeededImage(1, 2);
                    break;
                case 0:
                    buttons[i, j].Image = FindNeededImage(0, 0);
                    break;
            }
        }

        private static void OpenCells(int i,int j)
        {
            OpenCell(i, j);

            if (map[i, j] > 0)
                return;

            for(int k = i - 1; k < i + 2; k++)
            {
                for(int l = j - 1; l < j + 2; l++)
                {
                    if (!IsInBorder(k, l, n))
                        continue;
                    if (!buttons[k, l].Enabled)
                        continue;
                    if (map[k, l] == 0)
                        OpenCells(k, l);
                    else if (map[k, l] > 0)
                        OpenCell(k, l);
                }
            }
        }

        private static bool IsInBorder(int i,int j, int n)
        {
            if(i<0 || j<0 || j>mapSize[n] -1 || i > mapSize[n] - 1)
            {
                return false;
            }
            return true;
        }
    }
}
