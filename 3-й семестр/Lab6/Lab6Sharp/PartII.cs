using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6Sharp
{
    public class FunnyGame
    {
        public bool[,] matric;
        public FunnyGame(int n)
        {
            int stroka, stolbec;
            matric = new bool[n,n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matric[i,j] = false;
                }
            }
            Random rnd = new Random();
            for (int i = 0; i != n / 2; i++)
            {
                stroka= rnd.Next(0,n);
                stolbec= rnd.Next(0,n);
                while (matric[stroka,stolbec] == true)
                {
                    stroka = rnd.Next(0,n);
                    stolbec = rnd.Next(0, n);
                }
                matric[stroka, stolbec] = true;
            }
        }
        public bool isWin(int n)
        {
            Random rnd = new Random();
            int q = 0;
            for (int i = 0; i < n; i++)
            {
                if (matric[rnd.Next(0,n), rnd.Next(0, n)] == true) q++;
            }
            if (q >= (n / 3)) return true;
            else return false;
        }

        
    }
    class TaskII
    {
        public void PartII()
        {
            Random rnd = new Random();
            int n = int.Parse(Console.ReadLine());
            FunnyGame FG = new FunnyGame(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(Convert.ToInt32(FG.matric[i, j]));
                    Console.Write(" ");
                }
                Console.WriteLine("");
            }
            bool win = FG.isWin(n);
            if (win)
            {
                Console.WriteLine("\n win");
            }
            Console.WriteLine("\n lose");
            Console.ReadKey();
        }
    }
}
