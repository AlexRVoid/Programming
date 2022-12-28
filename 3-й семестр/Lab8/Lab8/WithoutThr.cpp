#include "WithoutThr.h"

void Sell::sell()
{
    
    vector<pair<string, int>> products = { {"Water", 30}, {"Apple", 150}, {"Milk", 90}, {"Glue", 200}, {"Solvent", 150}, {"gamma-Hydroxybutyric acid", 1000} , {"2,3,7,8-Tetrachlorodibenzodioxin", 5000} , {"1,2-Dichloroethane", 110} };
    srand(time(0));
    int chosenProducts = rand() % 7;
    cout << "The product " << products[chosenProducts].first << " was bought" << endl;
    earnings += products[chosenProducts].second;
    cout << "The total earnings are " << earnings << "Rub" << endl << endl;
    
}
void withoutThr()
{
	Sell sell;
    for (int i = 0; i < 10; i++)
    {
        sell.sell();
    }
    cout << "Time: " << clock();
    system("pause");
}