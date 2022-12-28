using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8Sharp
{
    public class SellStar
    {
        
        public void sell()
        {
            
            List<string> product = new List<string> { "Water", "Apple", "Milk", "Glue", "Solvent", "gamma-Hydroxybutyric acid", "2,3,7,8-Tetrachlorodibenzodioxin", "1,2-Dichloroethane" };
            List<int> money = new List<int> { 30, 150, 90, 200, 150, 1000, 5000 };
            Random rnd = new Random();
            int chosenProduct = rnd.Next(0, 7);
            Console.Write("The product ");
            Console.Write(product[chosenProduct]);
            Console.Write(" was bought\n");
            earnings += money[chosenProduct];
            Console.Write("The total earnings are ");
            Console.Write(earnings);
            Console.Write("Rub\n\n");
            
        }
        private int earnings = 0;
        public void star()
        {
            SellStar sell = new SellStar();
            for (int j = 0; j < 10; j++)
            {
                ThreadStart threadStart = new ThreadStart(sell.sell);
                Thread thread = new Thread(threadStart);
                thread.Start();
                Thread.Sleep(10);
                
            }
            Console.ReadKey();
        }
    }
}
