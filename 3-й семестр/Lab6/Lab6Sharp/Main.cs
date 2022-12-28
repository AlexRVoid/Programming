using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6Sharp
{
    static class Program
    {
        static int Main(string[] args)
        {
            try
            {
                TaskI task1 = new TaskI();
                TaskII task2 = new TaskII();

                Console.WriteLine("What task to complete(PartI - 1, PartII - 2, Exit - 3): ");
                int choice = int.Parse(Console.ReadLine());
                if (choice == 1)
                {
                    task1.PartI();
                }
                else if (choice == 2)
                {
                    task2.PartII();
                }
                else if (choice == 3)
                {
                    return 0;
                }
                Console.ReadKey();
                return 0;
            }
            catch
            {
                IncorrectInput e = new IncorrectInput();
                e.print();
                Console.ReadKey();
                return 0;
            }
        }
    }
}

