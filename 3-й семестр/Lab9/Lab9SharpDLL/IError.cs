using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9SharpDLL
{
    public class IError
    {
        public string description = "Error: ";
        public virtual void print()
        {
            Console.WriteLine(description);
        }
    }
    public class IncorrectInput : IError
    {
        public IncorrectInput() { }
        public void print()
        {
            Console.WriteLine("{1} Incorrect input", description);

        }
    }
    public class DivisionByZero : IError
    {
        public DivisionByZero() { }
        public void print()
        {
            Console.WriteLine("{1} Integer division by zero", description);
        }

    }
}
