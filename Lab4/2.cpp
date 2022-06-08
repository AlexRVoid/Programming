#include <iostream>
#include <vector>
#include <random>

using namespace std;

void randomNum(int n, vector <int>& massive)
{
    random_device rd;
    ranlux24_base gen(rd());
    uniform_int_distribution<> dist(10, 100);

    for (int i = 0; i < n; i++) {
        massive.push_back(dist(gen));
    }
}

void searchMin(vector <int>& massive) {
    cout << "\n// 2:\n";
    int min1 = massive[0], min2 = massive[1];
    for (auto i : massive) {
        if (min1 > i) min1 = i;
    }

    for (auto i : massive) {
        if ((min2 > i) and (i != min1)) min2 = i;
    }
    cout << min1 << " " << min2 << endl;
    int sum1 = 0, sum2 = 0;
    for (auto i : massive) {
        sum1 += i % min1;
        sum2 += i % min2;
    }
    cout << sum1 << " " << sum2 << endl;
}

void maxRange(vector <int>& numbers, vector <int>& max_numbers) {
    int num = 0, initial_num = 0, amount = 0, max_amount = 0;
    for (unsigned int i = 0; i < (numbers.size() - 1); i++) {
        if (amount == 0) num = i;
        if (numbers[i] < numbers[i + 1])
            amount++;
        else {
            if (max_amount < amount) {
                max_amount = amount;
                initial_num = num;
            }
            amount = 0;
        }
    }

    for (int i = initial_num; i < (initial_num + max_amount + 1); i++) {
        max_numbers.push_back(numbers[i]);
    }
}

void arrayNum(int N, vector < vector<int> >& arrNum) {
    int num = 2000;
    for (int i = 0; i < N; i++) {
        vector<int> line = {};
        for (int j = 0; j < 8; j++) {
            line.push_back(num);
            num += 10;
        }
        arrNum.push_back(line);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++)
            cout << arrNum[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    cout << "// 1:\n";
    cout << "Enter the number of elements:\n";
    int n;
    cin >> n;
    while (n < 10) {
        cout << "Enter a number at least 10:\n";
        cin >> n;
    }
    vector <int> massive;
    randomNum(n, massive);
    for (auto i : massive) cout << i << " ";
    cout << endl;
    searchMin(massive);

    cout << "\n// 3:\n";
    vector <int> numbers = { 18, 10, 19, 20, 25, 30, 47, 23, 1, 2, 3, 745, 0 };
    for (auto i : numbers) cout << i << " ";
    cout << endl;
    vector <int> max_numbers;
    maxRange(numbers, max_numbers);
    for (auto i : max_numbers) cout << i << " ";

    cout << "\n\n// 4:\n";
    cout << "Array N x 8:\n";
    cout << "Enter the number of columns (N):\n";
    int N = 0;
    cin >> N;
    vector < vector<int> > arrNum;
    arrayNum(N, arrNum);
}