using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Курсач
{
    public partial class LogInForm : Form
    {
        public LogInForm()
        {
            InitializeComponent();
            User_pass.UseSystemPasswordChar = true;
        }


        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Login_Click(object sender, EventArgs e)
        {
            if (User_name.Text == "admin" && User_pass.Text == "1111")
            {
                CryptoProtocolForm newForm = new CryptoProtocolForm();
                newForm.Show();
                this.Hide();
            }    
            else
            {
                User_name.Text = "";
                User_pass.Text = "";

                MessageBox.Show("Неверный логин или пароль!!!");
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkPass.Checked)
            {
                User_pass.UseSystemPasswordChar = false;
            }else User_pass.UseSystemPasswordChar = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
