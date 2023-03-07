// Неделя 13 Шахматы.cpp 

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int sizeChess = 6; // Размер доски
int arrChess[sizeChess][sizeChess]; // Шахматная доска которую мы заполним нулями
int Motion[8][2]{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}}; // Ходы 
int num1, num2; // Переменные в которые входит координаты + ход
int counter = 1 ; // Счетчик

void function( int x, int y)
{
	if (counter == sizeChess * sizeChess) // если счетчик равен размеру доски в квадрате (Число ходов которое необходимо для обхода доски) то мы выводим конечный результат!
	{

		for (int i = 0; i < sizeChess; i++)
		{
			for (int j = 0; j < sizeChess; j++)
			{
				cout << setw(3) << arrChess[i][j]; //  Функция setw делает матрицу ровной
			}
			cout << endl;
		}
		return ;
	}
	for (int i = 0; i < 8; i++)
	{
		num1 = x + Motion[i][0];
		num2 = y + Motion[i][1];
		if (arrChess[num1][num2] == 0 && num1 < sizeChess && num1 >= 0 && num2 < sizeChess && num2 >= 0 ) // Проверка  что мы можем сделать ход
		{
			counter++;
			arrChess[x + Motion[i][0]][y + Motion[i][1]] = counter;
			function(num1, num2); // рекурсия)
			arrChess[x + Motion[i][0]][y + Motion[i][1]] = 0;
			if (counter == sizeChess * sizeChess) // если счетчик равен размеру доски в квадрате(Число ходов которое необходимо для обхода доски) то откатываем до тех пор пока не выйдем из всех циклов и всех рекурсий
			{
				return;
			}
			counter--; // Если заходим в тупик то отнимаем от счетчика - 1 что б исключить повторения чисел
		}	
	}
	return ;
}

int main()
{
	setlocale(LC_ALL, "rus");
	
	cout << "Игра выведи коня c шахматной доски или ЕБ...ТЬ его конём!!!! " << endl;

	for (int i = 0; i < sizeChess; i++)
	{
		for (int j = 0; j < sizeChess; j++)
		{
			arrChess[i][j] = 0;
			cout << arrChess[i][j] << " ";
		}
		cout << endl;
	}

	int corrd1, corrd2;
	cout << "Введите кардинаты по оси X от 1 до  "<< sizeChess << endl;
	cin >> corrd2;
	cout << "Введите кардинаты по оси Y от 1 до  "<< sizeChess << endl;
	cin >> corrd1;
	corrd1--;
	corrd2--;
	arrChess[corrd1][corrd2] = 1; // Это число будет стоять по заданным координатам 

	function(corrd1, corrd2);
}
