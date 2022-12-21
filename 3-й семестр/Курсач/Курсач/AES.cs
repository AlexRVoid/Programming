using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;
using System.Windows.Forms;

namespace Курсач
{
    class AES
    {
        private byte[] encrypted;
        

        public string[] encryptKeyToString(byte[] Key)
        {
            string[] encryptkey = new string[Key.Length];

            for (int i = 0; i < Key.Length; i++)
            {
                encryptkey[i] = Key[i].ToString();
            }

            return encryptkey;
        }
        public string[] encryptIVToString(byte[] IV)
        {
            string[] encryptiv = new string[IV.Length];

            for (int i = 0; i < IV.Length; i++)
            {
                encryptiv[i] = IV[i].ToString();
            }

            return encryptiv;
        }

        public string[] encrypttextToString(byte[] encrypt)
        {
            string[] enctext = new string[encrypt.Length];
            for (int i = 0; i < encrypt.Length; i++)
            {
                enctext[i] = encrypt[i].ToString();
            }
            return enctext;
        }
            
        public byte[] StringToByte (string s, int keylength) 
        {

            string[] enctext = new string[keylength];
            byte[] result = new byte[keylength];
            for (int i = 0, j = 0; i < s.Length - 1 && j < keylength; i++)
            {
                enctext[j] += s[i];
                if (s[i] == ' ')
                    j++;
            }
            for (int i = 0; i < enctext.Length; i++)
            {
                result[i] = Convert.ToByte(enctext[i]);
            }
            return result;

            //byte[] result = new byte[keylength];
            //result = Encoding.ASCII.GetBytes(s);
            //return result;

        }

        public byte[] Encrypt_Aes(string soursetext, byte[] Key, byte[] IV)
        {
            // Check arguments.
            if (soursetext == null || soursetext.Length <= 0)
                MessageBox.Show("Не введён текст для шифровки");
            if (Key == null || Key.Length <= 0)
                MessageBox.Show("Введён неверный ключ шифровки");
            if (IV == null || IV.Length <= 0)
                MessageBox.Show("Введён неверный ключ шифровки");
            

            // Create an Aes object
            // with the specified key and IV.
            using (Aes aesAlg = Aes.Create())
            {
                aesAlg.Key = Key;
                aesAlg.IV = IV;

                // Create an encryptor to perform the stream transform.
                ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);

                // Create the streams used for encryption.
                using (MemoryStream msEncrypt = new MemoryStream())
                {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                        {
                            //Write all data to the stream.
                            swEncrypt.Write(soursetext);
                        }
                        encrypted = msEncrypt.ToArray();
                    }
                }
            }

            // Return the encrypted bytes from the memory stream.
            return encrypted;
        }

        public string Decrypt_Aes(byte[] cipherText, byte[] Key, byte[] IV)
        {
            // Проверка аргументов.
            if (cipherText == null || cipherText.Length <= 0)
                MessageBox.Show("Не введён текст для дешифровки");
            if (Key == null || Key.Length <= 0)
                MessageBox.Show("Введён неверный ключ шифровки");
            if (IV == null || IV.Length <= 0)
                MessageBox.Show("Введён неверный ключ шифровки");

            //Объяввление переменной для расшифрованного текста.
            string plaintext = null;

            // Создание объекта класса AES библиотеки System.Security.Cryptography
            using (Aes aesAlg = Aes.Create())
            {
                // Указание в качестве ключей дешифровки, пользовательских ключей
                aesAlg.Key = Key;
                aesAlg.IV = IV;

                // Создание дешифратора для выполнения преобразования потока.
                ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);

                // Создание потока для расшифровки
                using (MemoryStream msDecrypt = new MemoryStream(cipherText))
                {
                    using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                    {
                        using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                        {

                            // Чтение расшифрованных байтов из потокаи помещение их в строку для вывода
                            plaintext = srDecrypt.ReadToEnd();
                        }
                    }
                }
            }

            return plaintext;
        }

    }
}
