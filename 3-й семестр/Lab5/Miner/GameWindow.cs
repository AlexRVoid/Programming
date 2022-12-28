using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5
{
    public partial class GameWindow : Form
    {
        public GameWindow()
        {
            InitializeComponent();
            this.Size = new Size(400, 500);
            Difficulty.Show();
            Easy.Show();
            Medium.Show();
            Hard.Show();


        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Easy_Click(object sender, EventArgs e)
        {
            Game.n = 0;
            Difficulty.Hide();
            Easy.Hide();
            Medium.Hide();
            Hard.Hide();
            Game.Init(this);
        }

        private void Medium_Click(object sender, EventArgs e)
        {
            Game.n = 1;
            Difficulty.Hide();
            Easy.Hide();
            Medium.Hide();
            Hard.Hide();
            Game.Init(this);
        }

        private void Hard_Click(object sender, EventArgs e)
        {
            Game.n = 2;
            Difficulty.Hide();
            Easy.Hide();
            Medium.Hide();
            Hard.Hide();
            Game.Init(this);
        }
    }
}
