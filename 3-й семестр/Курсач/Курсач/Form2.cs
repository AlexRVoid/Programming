using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security.Cryptography;

namespace Курсач
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            Cryptoprotocol.Items.AddRange(new string[] { "AES", "RC4", "RSA"});
            Cryptoprotocol.SelectedIndexChanged += comboBox1_SelectedIndexChanged;

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Encrypt_Click(object sender, EventArgs e)
        {
            if (decrypt_text.Text != null && Cryptoprotocol.SelectedItem.ToString() == "AES")
            {
                AES aes = new AES();
                using (Aes Aes = Aes.Create())
                {
                    encrypt_text.Text = aes.Encrypt_Aes(decrypt_text.Text, Aes.Key, Aes.IV);
                }
            }
            else
            {
                MessageBox.Show("Выберите метод шифровки/дешифровки!!!");
            }
        }

        private void encrypt_text_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
