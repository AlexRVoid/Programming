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
    public partial class Game : Form
    {
        
        public Game()
        {
            InitializeComponent();
            MapController.Init(this);
        }

        private void Game_Load(object sender, EventArgs e)
        {

        }
        
       
        


    }
}

