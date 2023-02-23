// Жесткий массив
#include <iostream>
#include <ctime>
using namespace std;

void function(int arr[4][5], int arrS1, int arrS2, int numb, int timeN)
{
    for (int a = 0; a < numb; a++)
    {
        for (int i = 0; i < arrS1; i++)
        {
            timeN = arr[i][arrS2 - 1];
            for (int j = arrS2 - 1; j > 0; j--)
            {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = timeN;
        }
    }
    for (int i = 0; i < arrS1; i++)
    {
        for (int j = 0; j < arrS2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void function2(int arr[4][5], int arrS1, int arrS2, int numb, int timeN)
{
    for (int a = 0; a < numb; a++)
    {
        for (int i = 0; i < arrS1; i++)
        {
            for (int j = 0; j < arrS2; j++)
            {
                if ((i + 1) < (arrS2 - 1))
                {
                    timeN = arr[i][j];
                    arr[i][j] = arr[i + 1][j];
                    arr[i + 1][j] = timeN;
                }
            }
        }
    }
    for (int i = 0; i < arrS1; i++)
    {
        for (int j = 0; j < arrS2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");

    const int arraySize1 = 4;
    const int arraySize2 = 5;
    int array[arraySize1][arraySize2];

    int number = 0;
    int shift;

    for (int i = 0; i < arraySize1; i++)
    {
        for (int j = 0; j < arraySize2; j++)
        {
            array[i][j] = 1 + rand() % 9;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "В какую сторону двигаем массив?\n";
    cout << "Влево  = нажми 0\n";
    cout << "Вправо = нажми 1\n";
    cout << "Вверх  = нажми 2\n";
    cout << "Вниз   = нажми 3\n";
    cin >> shift;

    cout << "Введите число сдвигов : \n";
    cin >> number;
    int timeNumber = 0;
    int negative;

    switch (shift)
    {
    case 0:
        number = arraySize2 - number;
        if (number > arraySize2)
        {
            number = number * -1;
        }
        function(array, arraySize1, arraySize2, number, timeNumber);
        break;

    case 1:
        function(array, arraySize1, arraySize2, number, timeNumber);
        break;       
    case 2:
        function2(array, arraySize1, arraySize2, number, timeNumber);
        break;

    case 3:
        number = arraySize1 - number;
        if (number < 0)
        {
            number *= -1;
        }
        function2(array, arraySize1, arraySize2, number, timeNumber);
        break;
    }







}
