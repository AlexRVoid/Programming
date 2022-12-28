using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8Sharp
{
    internal class Programm
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine("What to do?");
                Console.WriteLine("1)Multithreading");
                Console.WriteLine("2)Single-threaded");
                Console.WriteLine("3)Exit");
                int choice = int.Parse(Console.ReadLine());
                
                if (choice == 1)
                {
                    Console.Clear();
                    Console.WriteLine("What topology should I perform?");
                    Console.WriteLine("1)Ring");
                    Console.WriteLine("2)Star");
                    Console.WriteLine("3)Exit");
                    int topology = int.Parse(Console.ReadLine());

                    if (topology == 1)
                    {
                        SellRing sell = new SellRing();
                        Console.Clear();
                        sell.ring();
                    }
                    else if (topology == 2)
                    {
                        SellStar sell = new SellStar();
                        Console.Clear();
                        sell.star();
                    }
                    else continue;
                }
                else if (choice == 2)
                {
                    SellWithoutThr sell = new SellWithoutThr();
                    Console.Clear();
                    sell.withoutThr();
                }
                else if (choice == 3)
                {

                    Environment.Exit(0);

                }
                else continue;
            }
        }
    }
}