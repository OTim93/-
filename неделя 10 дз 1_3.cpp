// Жесткий массив
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");

    const int arraySize1 = 4;
    const int arraySize2 = 5;
    int array[arraySize1][arraySize2];
   
    int number;
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
    int timeNumber;
   
    switch (shift)
    {
    case 0:
        for (int a = 0; a < number; a++)
        {
            for (int i = 0; i < arraySize1; i++)
            {
                timeNumber = array[i][0];
                for (int j = 0; j < arraySize2 - 1; j++)
                {
                    array[i][j] = array[i][j + 1];
                }
                array[i][arraySize2 - 1] = timeNumber;
            }
        }
        break;

    case 1:
        for (int a = 0; a < number; a++)
        {
            for (int i = 0; i < arraySize1; i++)
            {
                timeNumber = array[i][arraySize2 - 1];
                for (int j = arraySize2 - 1; j > 0; j--)
                {
                    array[i][j] = array[i][j - 1];
                }
                array[i][0] = timeNumber;
            }
        }
        break;

    case 2:
        for (int a = 0; a < number; a++)
        {
            for (int i = 0; i < arraySize1; i++)
            {
                for (int j = 0; j < arraySize2; j++)
                {
                    if ((i + 1) < (arraySize2 - 1))
                    {
                        timeNumber = array[i][j];
                        array[i][j] = array[i + 1][j];
                        array[i + 1][j] = timeNumber;
                    }
                }
            }
        }
        break;

    case 3:
        number = arraySize1 - number;
        if (number < 0)
        {
            number *= -1;
        }
        for (int a = 0; a < number; a++)
        {
            for (int i = 0; i < arraySize1; i++)
            {
                for (int j = 0; j < arraySize2; j++)
                {
                    if ((i + 1) < (arraySize2 - 1))
                    {
                        timeNumber = array[i][j];
                        array[i][j] = array[i + 1][j];
                        array[i + 1][j] = timeNumber;
                    }
                }
            }
        }
        break;
    }
        
    for (int i = 0; i < arraySize1; i++)
    {
        for (int j = 0; j < arraySize2; j++)
        {  
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
       





}

