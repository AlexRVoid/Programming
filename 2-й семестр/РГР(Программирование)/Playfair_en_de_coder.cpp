#include <iostream>
#include <string>

using namespace std;
//  " !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
//    char ascii[] = {' ','"','!','#','$','%','&','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\',']','^','_','\0x27','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~'};

void PlayfairEncoder(string mes, string key) {

    const int row = 5, column = 19;

    char matrix[row][column];

    //удаление из ключа повторяющихся символов
    string keycopy = "NLSTTLLU";
    string lol = " ";
    for (int i = 0; i < keycopy.size(); i++) {
        //lol = lol+keycopy[i];
        for (int j = i; j < keycopy.size(); j++) {
            if (keycopy[i] = keycopy[j+1]) {
                keycopy.erase(j+1, 1);
                break;
            }
        }
    }cout << keycopy;
    
    string ascii = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

    for (int c = 0; c < key.size(); c++)// запись ключа в начало матрицы
    {
        matrix[0][c] = key[c];
    }

    int i = 0, j = 0, m = 0, n = key.size()-1;
    // отбрасывание уже использованных в ключе символов и запись в матрицу оставшихся
    while (i < ascii.size()) {
        int p = 0;
        while (j < key.size()) {
            if (ascii[i] == key[j]) { //если символ в ascii и ключе совпал
                p = 1;// опускается флажок
                break;
            }
            j++;
        }
        if (p == 0) {// если флажок не опущен
            n = (n % 19) + 1;// записываем символ в n+1-й столбец матрицы
            if (n == 1) {// если столбцы закончились
                m = m + 1;// то переходим на новую строку
            }
            matrix[m][n] = ascii[i]; //то добавляем символ в матрицу
        }
    
    i++;
    j = 0;
}
    /*for (auto& subarray : matrix)// вывод матрицы (убрать!)
    {
        for (char a : subarray)
        {
            cout << a << "\t";
        }
        cout << endl;
    }*/
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}



int main() {
	PlayfairEncoder("AVE@AVE@AVTF!", "NSTU");// ЗАМЕНИТЬ НА ПЕРЕМЕННЫЕ "СООБЩЕНИЕ" И "КЛЮЧ"
	//PlayfairDecoder("15 5 17 21 15 5 17 21 15 5 0 19 111", "NSTU");// ЗАМЕНИТЬ НА ПЕРЕМЕННЫЕ " ЗАШИФРОВАННОЕ СООБЩЕНИЕ" И "КЛЮЧ"
}