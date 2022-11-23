
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
                Console.WriteLine("Private key: {0}\n", p_key);
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
                    Console.WriteLine("{0} ", encrypttext[i]);
                }
            }

            public void GetDecryptText()
            {
                for (int i = 0; i < decrypttext.Count(); i++)
                {
                    Console.WriteLine("{0} ", decrypttext[i]);
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
                Console.WriteLine("{0}`s Public Key: {1}\n", Name, ya);
            }

            public void SetXKey(int t, int p_key)
            {
                xa = 1;
                for (int i = 0; i < (t - 1); i++)
                {
                    xa = xa * p_key % p;
                }
                Console.WriteLine("{0}`s Private Key: {1}\n", Name, ya);
            }
            private int xa;
        }

        class SH
        {
            public int p;
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
                Console.WriteLine("y= {0}\n", y);
            }

            public void GetEncryptText()
            {
                for (int i = 0; i < encrypttext.Count; i++)
                {
                    Console.Write("{0} ", encrypttext[i]);
                }
            }

            public void GetDecryptText()
            {
                for (int i = 0; i < decrypttext.Count; i++)
                {
                    Console.Write("{0} ", decrypttext[i]);
                }
            }

            private int p_key;
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
                    Console.Write(" {0}",soursetext[i]);
                }
            }
        }

        void EncryptRSA(ref List<int> text)
        {
            RSA rsa = new();
            Random rnd = new Random();
            
            Console.Clear();
            Console.WriteLine("=========================RSA");

            Console.Write("Select the number p: ");
                rsa.Setp(Convert.ToInt32(Console.ReadLine()));

            Console.Write("Select the number q: ");
                rsa.Setq(Convert.ToInt32(Console.ReadLine()));

            rsa.Na = rsa.Getp() * rsa.Getq();

            rsa.GenOpenKey(rnd.Next(100, 10000));
            Console.WriteLine("Open key: {0}", rsa.o_key);

            rsa.GenPrivateKey();

            rsa.EncryptText(text);
            Console.WriteLine("Your encrypted text:");
            rsa.GetEncryptText();

            rsa.DecryptText();
            Console.WriteLine("Your decrypted text:");
            rsa.GetDecryptText();

            Console.ReadKey();
        }

        
        void EncryptDH()
        {
            DH dha = new DH();
            DH dhb = new DH();
            Random rnd = new Random();

            dha.Name = "Alice";
            dhb.Name = "Bob";

            while (true)
            {
                Console.Clear();
                Console.WriteLine("=========================Diffie-Hellman");
                string choice;
                Console.WriteLine("Enter numbers manually or automatically? (m / a)");
                choice = Console.ReadLine();

                if (choice == "m")
                {
                    Console.Write("Enter g: ");
                    dha.g = Convert.ToInt32(Console.ReadLine());
                    dhb.g = dha.g;
                    Console.Write("Enter p: ");
                    dha.p = Convert.ToInt32(Console.ReadLine());
                    dhb.p = dha.p;
                    Console.WriteLine("Your numbers are: {0} {1}", dha.g, dha.p);
                    break;
                }
                else if (choice == "a")
                {
                    dha.g = rnd.Next(100, 10000);
                    dhb.g = dha.g;
                    dha.p = rnd.Next(100, 10000);
                    dhb.p = dha.p;
                    Console.WriteLine("Your numbers are: {0} {1}", dha.g, dha.p);
                    break;
                }
                else
                {
                    Console.Clear();
                    Console.WriteLine("Incorrect data, try again");
                    Console.ReadKey();
                    continue;
                }
            }
            Console.Write("Come up with a secret number for Alice: ");
            int a = Convert.ToInt32(Console.ReadLine());
            dha.SetYKey(a);

            Console.Write("Come up with a secret number for Bob: ");
            int b = Convert.ToInt32(Console.ReadLine());
            dhb.SetYKey(b);

            dha.SetXKey(a, dhb.ya);

            dhb.SetXKey(b, dha.ya);

            Console.ReadKey();
        }

        int ost (int a, int x, int p)
        {
            int res = 1;
            for (int i = 0; i < x; i++)
            {
                res *= a;
                res %= p;
            }
            return res;
        }

        void EncryptElGam(ref List<int> text)
        {
            ElGam elgam = new ElGam(593, 123, 8);

            Console.Clear();
            Console.WriteLine("=========================ElGamal");

            for (int i = 0; i < text.Count; i++) //encrypt
            {
                int encelfist = 0, encelsecond = 0;

                encelfist = ost(elgam.g, elgam.k, elgam.p);
                encelsecond = ost(elgam.y, elgam.k, elgam.p);
                encelsecond = (encelsecond * text[i]) % elgam.p;

                elgam.encrel = new Tuple<int, int> (encelfist, encelsecond);
                elgam.encrypttext.Add(elgam.encrel);
            }

            for (int i = 0; i < elgam.encrypttext.Count; i++) //decrypt
            {
                elgam.decel = ost(elgam.encrypttext[i].Item1, elgam.p - 1 - elgam.GetPKey(), elgam.p);
                elgam.decel = elgam.decel * elgam.encrypttext[i].Item2 % elgam.p;

                elgam.decrypttext.Add(elgam.decel);
            }

            Console.Write("Your encrypted text: ");
            elgam.GetEncryptText();

            Console.WriteLine();

            Console.Write("Your decrypted text: ");
            elgam.GetDecryptText();

            Console.ReadKey();
        }

        int GenFirstKey(int p)
        {
            Random rnd = new Random();
            int ca = rnd.Next(1000, (p - 1));
            while (true)
            {
                if (ca > 0)
                {
                    if (ca % (p - 1) == 1)
                    {
                        return ca;
                    }
                    else ca -= 1;
                }
                else ca += (p - 1);
            }

        }

        int GenSecondKey(int ca, int p)
        {
            Random rnd = new Random();
            int da = rnd.Next(1000, (p - 1));
            while (true)
            {
                if (da > 0)
                {
                    if ((ca * da) % (p - 1) == 1)
                    {
                        return da;
                    }
                    else da -= 1;
                }
                else da += (p - 1);
            }
        }
        void EncryptSH(ref List<int> text)
        {
            Console.Clear();
            Console.WriteLine("=========================Shamir");
            Random rnd = new Random();

            int p = rnd.Next(1000, 10000);
            SH ash = new SH(p);
            SH bsh = new SH(p);

            ash.SetCa(GenFirstKey(ash.p));
            ash.Setda(GenSecondKey(ash.GetCa(), ash.p));

            bsh.SetCa(GenFirstKey(bsh.p));
            bsh.Setda(GenSecondKey(bsh.GetCa(), bsh.p));

            Console.WriteLine("p = {0}, Alice Ca = {1}, Alice Da = {2}, Bob Cb = {3}, Bob Db = {4}", ash.p, ash.GetCa(), ash.Getda(), bsh.GetCa(), bsh.Getda());

            Console.Write("Encrypto Alice = ");
            for (int i = 0; i < text.Count; i++)
            {
                int x1;
                x1 = ost(text[i], ash.GetCa(), ash.p);
                ash.x1.Add(x1);
                Console.Write("{0} ",ash.x1[i]);
            }

            Console.WriteLine();

            Console.Write("Encrypto Bob = ");
            for (int i = 0; i < ash.x1.Count; i++)
            {
                int x1;
                x1 = ost(ash.x1[i], bsh.GetCa(), bsh.p);
                bsh.x1.Add(x1);
                Console.Write("{0} ", bsh.x1[i]);
            }

            Console.WriteLine();

            Console.Write("Encrypto Alice = ");
            for (int i = 0; i < bsh.x1.Count; i++)
            {
                int x2;
                x2 = ost(bsh.x1[i], ash.Getda(), ash.p);
                ash.x2.Add(x2);
                Console.Write("{0} ", ash.x2[i]);
            }

            Console.WriteLine();

            Console.Write("Decrypto Bob = ");
            for (int i = 0; i < ash.x2.Count; i++)
            {
                int x2;
                x2 = ost(ash.x2[i], bsh.Getda(), bsh.p);
                bsh.x2.Add(x2);
                Console.Write("{0} ", bsh.x1[i]);
            }
            Console.ReadKey();
        }

        static int Main(string[] args)
        {
            var programm = new Programm();
            SourseText soursetext = new();
            string stext;

            Console.WriteLine("Enter the source text: ");
            stext = Console.ReadLine();

            Console.Clear();

            soursetext.SetSourseElement(stext);

            Console.WriteLine("Your text: {0}", stext);
            Console.Write("Transform text: ");
            soursetext.GetSourseText();
            Console.ReadKey();


            while(true)
            {
                Console.Clear();
                string num;
                Console.WriteLine("1.RSA \n2.Diffie-Hellman \n3.ElGamal \n4.Shamir \n5.Exit");
                num = Console.ReadLine();



                switch(num)
                {
                    case "1":
                        programm.EncryptRSA(ref soursetext.soursetext);
                        break;
                    case "2":
                        programm.EncryptDH();
                        break;
                    case "3":
                        programm.EncryptElGam(ref soursetext.soursetext);
                        break;
                    case "4":
                        programm.EncryptSH(ref soursetext.soursetext);
                        break;
                    case "5":
                        return 0;
                    default:
                        Console.Clear();
                        Console.WriteLine("Invalid number\n Try again");
                        Console.ReadKey();
                        break;
                }

            }
        }
    }
}

