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
using System.Net.NetworkInformation;

namespace Курсач
{
    public partial class CryptoProtocolForm : Form
    {
        public CryptoProtocolForm()
        {
            InitializeComponent();
            Cryptoprotocol.Items.AddRange(new string[] { "AES"});
            Cryptoprotocol.SelectedItem = "AES";
            Cryptoprotocol.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            Size = new Size(837, 699);
            

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (Cryptoprotocol.SelectedItem.ToString() == "AES")
            {
          

                Key1.Show();
                Key1.Text = "AES Key";

                Key2.Show();
                Key2.Text = "AES IV";

                CryptoKey1.Show();
                CryptoKey2.Show();
            }
         
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Encrypt_Click(object sender, EventArgs e)
        {
            encrypt_text.Clear();
            if (decrypt_text.Text != null && Cryptoprotocol.SelectedItem.ToString() == "AES")
            {
                AES aes = new AES();
                using (Aes Aes = Aes.Create())
                {

                    string[] enckey = aes.encryptKeyToString(Aes.Key);
                    CryptoKey1.Text = null;
                    for (int i = 0; i < enckey.Length; i++)
                    {
                        
                        CryptoKey1.Text += enckey[i];

                        CryptoKey1.Text += " ";
                    }

                    string[] enciv = aes.encryptIVToString(Aes.IV);
                    CryptoKey2.Text = null;
                    for (int i = 0; i < enciv.Length; i++)
                    {
                        CryptoKey2.Text += enciv[i];

                        CryptoKey2.Text += " ";
                    }
                    if (CryptoKey1.Text == "" || CryptoKey2.Text == "")
                    {
                        string[] enctext = aes.encrypttextToString(aes.Encrypt_Aes(decrypt_text.Text, Aes.Key, Aes.IV));
                        for (int i = 0; i < enctext.Length; i++)
                        {
                            encrypt_text.Text += enctext[i];

                            encrypt_text.Text += " ";
                        }
                    }
                    else if (CryptoKey1.Text != "" && CryptoKey2.Text != "" && decrypt_text.Text != null)
                    {
                        if (aes.StringToByte(CryptoKey1.Text, 32, true).Length == 32 && aes.StringToByte(CryptoKey2.Text, 16, true).Length == 16)
                        {
                            string[] enctext = aes.encrypttextToString(aes.Encrypt_Aes(decrypt_text.Text, aes.StringToByte(CryptoKey1.Text, 32, true), aes.StringToByte(CryptoKey2.Text, 16, true)));
                            if (enctext != null && enctext.Length > 0)
                            {
                                for (int i = 0; i < enctext.Length; i++)
                                {
                                    encrypt_text.Text += enctext[i];

                                    encrypt_text.Text += " ";
                                }
                            }
                        }
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
            decrypt_text.Text = null;
            try
            {
                if (encrypt_text.Text != null && Cryptoprotocol.SelectedItem.ToString() == "AES")
                {
                    AES aes = new AES();
                    using (Aes Aes = Aes.Create())
                    {
                        if ((CryptoKey1.Text != "" && CryptoKey2.Text != "") && (aes.StringToByte(CryptoKey1.Text, 0, true) != null && aes.StringToByte(CryptoKey2.Text, 0, true) != null) && (aes.StringToByte(CryptoKey1.Text, 0, true).Length == 32 && aes.StringToByte(CryptoKey2.Text, 0, true).Length == 16))
                        {


                            string dectext = aes.Decrypt_Aes(aes.StringToByte(encrypt_text.Text, 0, true), aes.StringToByte(CryptoKey1.Text, 32, true), aes.StringToByte(CryptoKey2.Text, 16, true));

                            decrypt_text.Text += dectext;

                            decrypt_text.Text += "\n";

                        }

                        else
                        {
                            MessageBox.Show("Введён неверный ключ шифровки");
                            CryptoKey1.Text = null;
                            CryptoKey2.Text = null;
                        }
                    }
                }
            }catch
            {
                MessageBox.Show("Ошибка шифровки / дешифровки.");
            }
        }

        private void Encrypt_to_file_Click(object sender, EventArgs e)
        {

           

            
            FileStream file = new FileStream("Encrypt text.txt", FileMode.Create);
            StreamWriter stream = new StreamWriter(file);
            stream.WriteLine("Aes key:");
            stream.WriteLine(CryptoKey1.Text);
            stream.WriteLine("AES IV:");
            stream.WriteLine(CryptoKey2.Text);
            stream.WriteLine("Encrypt text:");
            stream.Write(encrypt_text.Text);
            stream.Close();
            file.Close();
            MessageBox.Show("Файл успешно записан.");
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            FileStream file = new FileStream("Decrypt text.txt", FileMode.Create);
            StreamWriter stream = new StreamWriter(file);
            stream.WriteLine("Aes key:");
            stream.WriteLine(CryptoKey1.Text);
            stream.WriteLine("AES IV:");
            stream.WriteLine(CryptoKey2.Text);
            stream.WriteLine("Decrypt text:");
            stream.Write(decrypt_text.Text);
            stream.Close();
            file.Close();
            MessageBox.Show("Файл успешно записан.");
        }

        private void encrypt_text_KeyPress(object sender, KeyPressEventArgs e)
        {

            char number = e.KeyChar;

            if (!Char.IsDigit(number) && e.KeyChar != 32)
            {
                e.Handled = true;
            }
        }

        private void CryptoKey1_KeyPress(object sender, KeyPressEventArgs e)
        {
            char number = e.KeyChar;

            if (!Char.IsDigit(number) && e.KeyChar != 32)
            {
                e.Handled = true;
            }
        }

        private void CryptoKey2_KeyPress(object sender, KeyPressEventArgs e)
        {
            char number = e.KeyChar;

            if (!Char.IsDigit(number) && e.KeyChar != 32)
            {
                e.Handled = true;
            }
        }
    }
}
