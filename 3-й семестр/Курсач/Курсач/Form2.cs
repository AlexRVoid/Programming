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
            Cryptoprotocol.SelectedItem = "AES";
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
            encrypt_text.Text = null;
            if (decrypt_text.Text != null && Cryptoprotocol.SelectedItem.ToString() == "AES")
            {
                AES aes = new AES();
                using (Aes Aes = Aes.Create())
                {

                    string[] enckey = aes.encryptKeyToString(Aes.Key);
                    CryptoKey.Text += "AES Key: ";
                    for (int i = 0; i < enckey.Length; i++)
                    {
                        
                        CryptoKey.Text += enckey[i];

                        encrypt_text.Text += " ";
                    }

                    string[] enciv = aes.encryptIVToString(Aes.IV);
                    CryptoKey.Text += "\n\nAES IV: ";
                    for (int i = 0; i < enciv.Length; i++)
                    {
                        CryptoKey.Text += enciv[i];

                        encrypt_text.Text += " ";
                    }

                    string[] enctext = aes.encrypttextToString(aes.Encrypt_Aes(decrypt_text.Text, Aes.Key, Aes.IV));
                    for (int i = 0; i < enctext.Length; i++)
                    {
                        encrypt_text.Text += enctext[i];

                        encrypt_text.Text += "\n";
                    }
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

        private void CryptoKey_TextChanged(object sender, EventArgs e)
        {

        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Decrypt_Click(object sender, EventArgs e)
        {

        }
    }
}
