using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6Sharp
{
    class IError
    {
        public string description = "Error: ";
        public virtual void print()
        {
            Console.WriteLine(description);
        }
    }
    class IncorrectInput : IError
    {
        public IncorrectInput() { }
        public void print()
        {
            Console.WriteLine("{1} Incorrect input", description);

        }
    }
    class DivisionByZero : IError
    {
        public DivisionByZero() { }
        public void print()
        {
            Console.WriteLine("{1} Integer division by zero", description);
        }

    }
}
