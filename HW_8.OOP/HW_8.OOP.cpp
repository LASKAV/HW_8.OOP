#include <iostream>
#include <random>
#include "New_Reelr.h"
using namespace std;

/*
Создать имитацию игры «однорукий бандит». Например, 
при нажатии кнопки «Enter» происходит «вращение» 
трех барабанов (естественно, количество шагов вращений 
каждого из них выбирается случайно), на которых
изображены разные значки; и если выпадает определенная 
комбинация, то игрок получает какой-то выигрыш
(использовать кольцевую очередь).
*/
int main()
{
	int num_max = 3;

	Reel Reel_one(num_max);
	// Нам нужно 3 переменных 
	// в котором будут рандомные числа 
	// а уже эти числа явно будем выводить в сhar

	srand(time(NULL));
	int num_one = 1 + rand() % 6; // 1 - > 6
	int num_two = 1 + rand() % 6;
	int num_three = 1 + rand() % 6;

	// Reel_one.GetCount();
	// Reel_one.IsEmpty();
	// Reel_one.IsFull();
	// Reel_one.Extract();

	int num = NULL;

	short num_spin = NULL;
	short num_win = NULL;
	short num_losing = NULL;
	short money = 1000;
	do
	{
		cout << "1.Spin" << endl
			<< "2.Statistics" << endl
			<< "3.Exit" << endl
			<< "\nYou money : " << money << endl;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			int num_one = 1 + rand() % 6; // 1 - > 6
			int num_two = 1 + rand() % 6;
			int num_three = 1 + rand() % 6;

			Reel_one.Add(num_one);
			Reel_one.Add(num_two);
			Reel_one.Add(num_three);

			Reel_one.Show();
			if (num_one == num_two || 
				num_two == num_three)
			{
				num_win++;
				money+=50;
				cout << "\nYou win: " << num_win << endl;
			}
			else if (num_one != num_two ||
				num_two != num_three)
			{
				num_losing++;
				money-=15;
				cout << "\nlosing: " << num_losing << endl;
				
			}
			Reel_one.Clear();
			num_spin++;
			cout  << "\nSpin : " << num_spin << endl;
			break;
		}
		case 3:
		{
			cout << "Game over" << endl;
			system("pause");
			num = 0;
			break;
		}
		case 2:
			system("cls");
			cout
				<< "\nStatistics" << endl
				<< "Spin : " << num_spin << endl
				<< "You win: " << num_win << endl
				<< "losing: " << num_losing << endl
				<< "Money: " << money << endl << endl;

			break;

		default:
			break;
		}
	} while (num != 0);
}

