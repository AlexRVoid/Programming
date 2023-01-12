#include "Ring.h"

void SellRing::sell()
{

    mx.lock();
    vector<pair<string, int>> products = { {"Water", 30}, {"Apple", 150}, {"Milk", 90}, {"Glue", 200}, {"Solvent", 150}, {"gamma-Hydroxybutyric acid", 1000} , {"2,3,7,8-Tetrachlorodibenzodioxin", 5000} , {"1,2-Dichloroethane", 110} };
    srand(time(0));
    int chosenProducts = rand() % 7;
	cout << "Cash: ";
    cout << "The product " << products[chosenProducts].first << " was bought" << endl;
    earnings += products[chosenProducts].second;
    cout << "The total earnings are " << earnings << "Rub" << endl << endl;
    mx.unlock();
}

void SellRing::ring() 
{
    
	for (int i = 0; i < 2; i++)
	{
		for (int i = 0; i < 2; i++)
		{
			thread th1([&]() {
				
				for (int i = 0; i < 5; i++)
				{
					
					sell();
				}
				
				});
			
			thread th2([&]() {
				
				for (int i = 0; i < 5; i++)
				{
					
					sell();
				}
				
				});
			
			thread th3([&]() {
				
				for (int i = 0; i < 5; i++)
				{
					
					sell();
				}
				
				});
			th1.join();
			th2.join();
			th3.join();
		}
	}
	cout << "Time: " << clock();
	system("pause");
}