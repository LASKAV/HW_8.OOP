#pragma once
#include <iostream>
using namespace std;

class Reel  // Барабан 
{
	//Очередь
	int* Wait;
	//Максимальный размер очереди
	int Max_Length;
	//Текущий размер очереди
	int Real_Length;
public:
	//Конструктор
	Reel(int m);
	//Деструктор
	~Reel();
	//Добавление элемента
	void Add(int c);
	//Извлечение элемента
	bool Extract();
	//Очистка очереди
	void Clear();
	//Проверка существования элементов в очереди
	bool IsEmpty();
	//Проверка на переполнение очереди
	bool IsFull();
	//Количество элементов в очереди
	int GetCount();
	//демонстрация очереди
	void Show();
};
void Reel::Show() {
	cout << "\n\n";
	//демонстрация очереди
	for (int i = 0; i < Real_Length; i++) {
		cout << "\t" << char(Wait[i]) << " ";
	}
	cout << "\n\n";
}
Reel::~Reel()  // Деструктор 
{
	//удаление очереди
	delete[]Wait;
}
Reel::Reel(int num_max)  // Конструктор
{
	//получаем размер
	Max_Length = num_max;
	//создаем очередь
	Wait = new int[Max_Length];
	//Изначально очередь пуста
	Real_Length = 0;
}
void Reel::Clear()
{
	//Эффективная "очистка" очереди
	Real_Length = 0;
}
bool Reel::IsEmpty()
{
	//Пуст?
	return Real_Length == 0;
}
bool Reel::IsFull()
{
	// Полон?
	return Real_Length == Max_Length;
}
int Reel::GetCount()
{
	//Количество присутствующих в стеке элементов
	return Real_Length;
}
void Reel::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull())
		Wait[Real_Length++] = c;
}
bool Reel::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < Real_Length; i++)
			Wait[i - 1] = Wait[i];
		//забрасываем первый "вытолкнутый элемент
		//в конец"
		Wait[Real_Length - 1] = temp;
		return 1;
	}
	else return 0;
}
