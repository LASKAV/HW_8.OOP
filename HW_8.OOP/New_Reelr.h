#pragma once
#include <iostream>
using namespace std;

class Reel  // ������� 
{
	//�������
	int* Wait;
	//������������ ������ �������
	int Max_Length;
	//������� ������ �������
	int Real_Length;
public:
	//�����������
	Reel(int m);
	//����������
	~Reel();
	//���������� ��������
	void Add(int c);
	//���������� ��������
	bool Extract();
	//������� �������
	void Clear();
	//�������� ������������� ��������� � �������
	bool IsEmpty();
	//�������� �� ������������ �������
	bool IsFull();
	//���������� ��������� � �������
	int GetCount();
	//������������ �������
	void Show();
};
void Reel::Show() {
	cout << "\n\n";
	//������������ �������
	for (int i = 0; i < Real_Length; i++) {
		cout << "\t" << char(Wait[i]) << " ";
	}
	cout << "\n\n";
}
Reel::~Reel()  // ���������� 
{
	//�������� �������
	delete[]Wait;
}
Reel::Reel(int num_max)  // �����������
{
	//�������� ������
	Max_Length = num_max;
	//������� �������
	Wait = new int[Max_Length];
	//���������� ������� �����
	Real_Length = 0;
}
void Reel::Clear()
{
	//����������� "�������" �������
	Real_Length = 0;
}
bool Reel::IsEmpty()
{
	//����?
	return Real_Length == 0;
}
bool Reel::IsFull()
{
	// �����?
	return Real_Length == Max_Length;
}
int Reel::GetCount()
{
	//���������� �������������� � ����� ���������
	return Real_Length;
}
void Reel::Add(int c)
{
	//���� � ������� ���� ��������� �����,
	//�� ����������� ����������
	//�������� � ��������� ����� �������
	if (!IsFull())
		Wait[Real_Length++] = c;
}
bool Reel::Extract()
{
	//���� � ������� ���� ��������, �� ���������� ���,
	//������� ����� ������ � �������� �������
	if (!IsEmpty()) {
		//��������� ������
		int temp = Wait[0];
		//�������� ��� ��������
		for (int i = 1; i < Real_Length; i++)
			Wait[i - 1] = Wait[i];
		//����������� ������ "����������� �������
		//� �����"
		Wait[Real_Length - 1] = temp;
		return 1;
	}
	else return 0;
}
