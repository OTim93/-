// Информационная система "сотрудник" 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#define num 100

using namespace std;

struct staff
{
	string empl_name;
	string surname;
	string age;
}arr[num];

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number = 0;
	int counter = 0;
	string time_name;
	char time_surname;
	string myfile = "myfile.txt";

	ifstream file;
	file.open(myfile);
	while (!file.eof())
	{
		file >> time_name;
		counter++;
	}
	file.clear();
	file.seekg(0);

	counter /= 3;

	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			
			if (j == 0)
			{
				file >> arr[i].empl_name;
			}
			if (j == 1)
			{
				file >> arr[i].surname;
			}
 			if (j == 2)
			{
				file >> arr[i].age;
			}
		}
	}
	file.seekg(0);
	file.clear();
	file.close();

	while (true)
	{
		
		system("cls");
		cout << "Терминал для работы учета сотрудников" << endl;
		cout << "Введите нужный параграф" << endl;
		cout << "1- Ввести сотрудника" << endl;
		cout << "2- Вывести на экран всех сотрудников" << endl;
		cout << "3- Поиск сотрудника по фамилии" << endl;
		cout << "4- Поиск сотрудника по первой буквы фамилии" << endl;
		cout << "5- Поиск сотрудника по возрасту" << endl;
		cout << "6- Удаление сотрудника" << endl;
		cout << endl;
		cin >> number;


		switch (number)
		{
		case 1:
		{
			system("cls");
			cout << "Введите имя сотрудника предприятия" << endl;
			cin >> arr[counter].empl_name;
			cout << "Введите фамилию сотрудника предприятия" << endl;
			cin >> arr[counter].surname;
			cout << "Введите возраст сотрудника" << endl;
			cin >> arr[counter].age;
			counter++;
			break;
		}
		case 2:
		{
			system("cls");
			cout << setw(10) << "Имя" << setw(15) << "Фамилия" << setw(10) << "Возраст" << endl;
			cout << endl;
			for (int i = 0; i < counter; i++)
			{
				cout << setw(10) << arr[i].empl_name << setw(15) << arr[i].surname << setw(10) << arr[i].age << endl;
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Введите фамилию сотрудника предприятия которого необходимо найти" << endl;
			cin >> time_name;
			for (int i = 0; i < counter; i++)
			{
				if (time_name == arr[i].surname)
				{
					cout << setw(10) << "Имя" << setw(15) << "Фамилия" << setw(10) << "Возраст" << endl;
					cout << endl;
					cout << setw(10) << arr[i].empl_name << setw(15) << arr[i].surname << setw(10) << arr[i].age << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Введите первую букву фамилии сотрудника предприятия которого необходимо найти" << endl;
			cin >> time_surname;
			for (int i = 0; i < counter; i++)
			{
				if (time_surname == arr[i].surname[0])
				{
					cout << setw(10) << "Имя" << setw(15) << "Фамилия" << setw(10) << "Возраст" << endl;
					cout << endl;
					cout << setw(10) << arr[i].empl_name << setw(15) << arr[i].surname << setw(10) << arr[i].age << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "Введите сотрудника сотрудника предприятия которого необходимо найти" << endl;
			cin >> time_name;
			for (int i = 0; i < counter; i++)
			{
				if (time_name == arr[i].age)
				{
					cout << setw(10) << "Имя"<< setw(15)<<"Фамилия" << setw(10) << "Возраст" << endl;
					cout << endl;
					cout << setw(10) << arr[i].empl_name << setw(15) << arr[i].surname << setw(10) << arr[i].age << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		}
		case 6:
		{
		
			cout << "Введите фамилию сотрудника которого уволили" << endl;
			cin >> time_name;
			for (int i = 0; i < counter; i++)
			{
				bool check = false;
				if (time_name == arr[i].surname || check == true)
				{
					arr[i].empl_name = arr[i+1].empl_name;
					arr[i].surname = arr[i+1].surname;
					arr[i].age = arr[i+1].age;
					check = true;
				}
			}
			counter--;
			system("pause");
			break;
		}
		}
		ofstream file;
		file.open(myfile);

		for (int i = 0; i < counter; i++)
		{
			file << arr[i].empl_name <<" "<< arr[i].surname << " " << arr[i].age << endl;
		}

		file.close();
    }	
}

