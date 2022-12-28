using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9SharpDLL
{

    public class Fraction
    {
        public int numerator, denominator;
        private List<string> logger = new List<string>();
        public Fraction()
        {
            numerator = 0;
            denominator = 1;

            logger.Add("Create default Fraction\n");
            Console.Write("Create default Fraction\n");
        }
        public Fraction(int a, int b)
        {
            int getNod = nod(a, b);
            numerator = a / getNod;
            denominator = b / getNod;

            if (b == 0)
            {
                Console.Write("denominator could not be 0, now denominator = 1\n");
                denominator = 1;
            }

            if (numerator < 0 && denominator < 0) { numerator *= -1; denominator += -1; }


            logger.Add("Create new Fraction\n");
            Console.Write("Create new Fraction\n");

        }

        static int nod(int a, int b)
        {
            int t;
            if (a < b) { t = a; a = b; b = t; }
            while (b != 0)
            {
                t = b;
                b = a % b;
                a = t;
            }
            return a;
        }
        static void swap(int a, int b)
        {
            int c;
            c = a;
            a = b;
            b = a;

        }


        public static Fraction operator +(Fraction fraction1, Fraction fraction2)
        {
            if (fraction2.denominator == fraction1.denominator)
            {
                Fraction fraction = new Fraction((fraction1.numerator + fraction2.numerator), (fraction1.denominator));
                return fraction;
            }
            else
            {
                int sum_den = fraction2.denominator * fraction1.denominator;
                int sum_num = fraction2.numerator * fraction1.denominator + fraction1.numerator * fraction2.denominator;
                Fraction fraction = new Fraction((sum_num), (sum_den));
                return fraction;
            }

            fraction1.logger.Add("Do summary\n");
            Console.Write("Do summary\n");

        }
        public static Fraction operator -(Fraction fraction1, Fraction fraction2)
        {
            if (fraction2.denominator == fraction1.denominator)
            {
                Fraction fraction = new Fraction((fraction1.numerator - fraction2.numerator), (fraction1.denominator));
                return fraction;
            }
            else
            {
                int sum_den = fraction2.denominator * fraction1.denominator;
                int sum_num = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
                Fraction fraction = new Fraction((sum_num), (sum_den));
                return fraction;
            }
        }
        public static Fraction operator /(Fraction fraction1, Fraction fraction2)
        {
            try
            {
                swap(fraction2.numerator, fraction2.denominator);
                fraction1.logger.Add("DIVISION OBJECT\n");
                Console.Write("DIVISION OBJECT\n");
                Fraction fraction = new Fraction(fraction2.numerator * fraction1.numerator, fraction2.denominator * fraction1.denominator);
                return fraction;
            }
            catch
            {
                IncorrectInput e = new IncorrectInput();
                e.print();
                return null;
            }
        }
        public static Fraction operator *(Fraction fraction1, Fraction fraction2)
        {
            fraction1.logger.Add("MULTIPLE OBJECT\n");
            Console.Write("MULTIPLE OBJECT\n");
            Fraction fraction = new Fraction(fraction2.numerator * fraction1.numerator, fraction2.denominator * fraction1.denominator);
            return fraction;
        }
        public static bool operator <(Fraction fraction1, Fraction fraction2)
        {
            fraction1.logger.Add("LESS OPERATOR\n");
            Console.Write("LESS OPERATOR\n");
            if (fraction2.denominator == fraction1.denominator)
            {
                return fraction1.numerator < fraction2.numerator;
            }
            else return fraction1.numerator * fraction2.denominator < fraction2.numerator * fraction1.denominator;
        }
        public static bool operator <=(Fraction fraction1, Fraction fraction2)
        {
            fraction1.logger.Add("EQUALS OR LESS OPERATOR\n");
            Console.Write("EQUALS OR LESS OPERATOR\n");
            if (fraction2.denominator == fraction1.denominator)
            {
                return fraction1.numerator <= fraction2.numerator;
            }
            else return fraction1.numerator * fraction2.denominator <= fraction2.numerator * fraction1.denominator;
        }

        public static bool operator >(Fraction fraction1, Fraction fraction2)
        {
            fraction1.logger.Add("LESS OPERATOR\n");
            Console.Write("LESS OPERATOR\n");
            if (fraction2.denominator == fraction1.denominator)
            {
                return fraction1.numerator > fraction2.numerator;
            }
            else return fraction1.numerator * fraction2.denominator > fraction2.denominator * fraction1.denominator;

        }
        public static bool operator >=(Fraction fraction1, Fraction fraction2)
        {
            fraction1.logger.Add("EQUALS OR MORE OPERATOR\n");
            Console.Write("EQUALS OR MORE OPERATOR\n");
            if (fraction2.denominator == fraction1.denominator)
            {
                return fraction1.numerator >= fraction2.numerator;
            }
            else return fraction1.numerator * fraction2.denominator >= fraction2.numerator * fraction1.denominator;
        }

    }
    public class TaskI
    {
        public void PartI()
        {
            Fraction number1 = new Fraction(7, 23);
            Fraction number2 = new Fraction();

            Console.WriteLine("numerator: ");
            number2.numerator = int.Parse(Console.ReadLine());
            Console.WriteLine("denominator: ");
            number2.denominator = int.Parse(Console.ReadLine());

            Console.WriteLine(number1 > number2);
            Console.WriteLine(number1 >= number2);
            Console.WriteLine(number1 < number2);
            Console.WriteLine(number1 <= number2);
            Console.WriteLine(number1 + number2);
            Console.WriteLine(number1 - number2);
            Console.WriteLine(number1 * number2);
            Console.WriteLine(number1 / number2);
            Console.ReadKey();
        }

    }

}
