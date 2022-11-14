
namespace Programm
{
    class Programm
    {
        class RSA
        {
            public int o_key;
            public int Na;

            public int Getq()
            {
                return q;
            }
            public int Getp()
            {
                return p;
            }
            public int Getpkey()
            {
                return p_key;
            }

            public void Setq(int iq)
            {
                q = iq;
            }
            public void Setp(int ip)
            {
                p = ip;
            }

            public void GenOpenKey(int n)
            {
                while (true)
                {
                    o_key = n;
                    if (o_key % ((p - 1) * (q - 1)) == 1)
                    {
                        o_key = n;
                        break;
                    }
                    else
                    {
                        n--;
                    }
                }
            }

            public void GenPrivateKey()// генерация закрытого ключа 
            {
                int k = 1;

                while (true)
                {
                    k = k + ((p - 1) * (q - 1));

                    if (k % o_key == 0 && k / o_key != 1)
                    {
                        p_key = (k / o_key);
                        break;
                    }
                }
                Console.WriteLine("Private key: {p_key}\n");
            }

            public void EncryptText(List<int> stext)// шифровка текста
            {
                for (int i = 0; i < stext.Count(); i++)
                {
                    int current;
                    int result;
                    current = stext[i] - 97;
                    result = 1;

                    for (int j = 0; j < o_key; j++)
                    {
                        result = result * current;
                        result = result % Na;
                    }

                    encrypttext.Add(result);
                }
            }

            public void DecryptText()// дешифровка текста 
            {

                for (int i = 0; i < encrypttext.Count(); i++)
                {
                    int current, result;

                    current = encrypttext[i];
                    result = 1;

                    for (int j = 0; j < p_key; j++)
                    {
                        result = result * current;
                        result = result % Na;
                    }

                    decrypttext.Add(result + 97);
                }
            }

            public void GetEncryptText()
            {
                for (int i = 0; i < encrypttext.Count(); i++)
                {
                    Console.WriteLine("{encrypttext[i]} ");
                }
            }

            public void GetDecryptText()
            {
                for (int i = 0; i < decrypttext.Count(); i++)
                {
                    Console.WriteLine("{decrypttext[i]} ");
                }
            }

            private List<int> encrypttext = new List<int>();
            private List<int> decrypttext = new List<int>();
            private int q;
            private int p;
            private int p_key;
        }

        class DH
        {
            public int p, g, ya;
            public string Name;

            public int GetXKey()
            {
                return xa;
            }

            public void SetYKey(int t)
            {
                ya = 1;
                for (int i = 0; i < (t - 1); i++)
                {
                    ya = ya * g % p;
                }
                Console.WriteLine("{Name}`s Public Key: {ya}\n");
            }

            public void SetXKey(int t, int p_key)
            {
                xa = 1;
                for (int i = 0; i < (t - 1); i++)
                {
                    xa = xa * p_key % p;
                }
                Console.WriteLine("{Name}`s Private Key: {ya}\n");
            }
            private int xa;
        }

        class SH
        {
            int p;
            public List<int> x1 = new List<int>();
            public List<int> x2 = new List<int>();

            public SH(int a) { p = a; Ca = 0; da = 0; }

            public int GetCa()
            {
                return Ca;
            }

            public void SetCa(int a)
            {
                Ca = a;
            }

            public int Getda()
            {
                return da;
            }


            public void Setda(int a)
            {
                da = a;
            }

            private int Ca, da;
        }

        class ElGam
        {
            public int p, g, y, k, decel;
            public Tuple<int, int> encrel;
            public List<Tuple<int, int>> encrypttext = new List<Tuple<int, int>>();
            public List<int> decrypttext = new List<int>();

            public ElGam(int a, int b, int d)
            {
                p = a; g = b; y = 1; p_key = d; decel = 1; k = 10;
            }

            public int GetPKey()
            {
                return p_key;
            }

            public void GenKey(int a, int x, int m)
            {
                y = 1;
                for (int i = 0; i < x; i++)
                {
                    y *= a;
                    y %= m;
                }
                Console.WriteLine("y= {y}\n");
            }

            public void GetEncryptText()
            {
                for (int i = 0; i < encrypttext.Count; i++)
                {
                    Console.WriteLine(encrypttext[i]);
                }
            }

            public void GetDecryptText()
            {
                for (int i = 0; i < decrypttext.Count; i++)
                {
                    Console.WriteLine(decrypttext[i]);
                }
            }

            private int p_key;
        }

        class EG
        {
            public int p, g, k, Da, Db, e, r, m;

            public EG(int a, int b, int c)
            {
                p = a; g = b; k = c; Ca = 0; Cb = 0; Da = 0; Db = 0; e = 0; r = 0; m = 0;
            }

            public int GetCa()
            {
                return Ca;
            }

            public int GetCb()
            {
                return Cb;
            }

            public void SetCa(int a)
            {
                Ca = a;
            }

            public void SetCb(int b)
            {
                Cb = b;
            }


            private int Ca, Cb;
        }

        class SourseText
        {
            public List<int> soursetext = new List<int>();

            public void SetSourseElement(string stext)
            {
                for (int i = 0; i < stext.Length; i++)
                {
                    int q = stext[i];
                    soursetext.Add(q);
                }
            }
            public void GetSourseText()
            {
                for (int i = 0; i < soursetext.Count; i++)
                {
                    Console.WriteLine(soursetext[i]);
                }
            }
            public List<int> GetTextForEncrypt()
            {
                return soursetext;
            }

        }

        static void Main(string[] args)
        {
            SourseText soursetext = new();
            string num;
            string stext;

            Console.WriteLine("Enter the source text: ");
            stext = Console.ReadLine();

            Console.Clear();
            

        }
    }
}

