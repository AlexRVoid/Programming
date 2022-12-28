using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab9SharpDLL;

internal class Program
{
    private static int Main(string[] args)
    {
        try
        {
            TaskI task1 = new TaskI();
            

            Console.WriteLine("What task to complete(PartI - 1, Exit - 2): ");
            int choice = int.Parse(Console.ReadLine());
            if (choice == 1)
            {
                task1.PartI();
            }
            else if (choice == 2)
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