// 4sem1lab.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "iostream"
#include "time.h"

using namespace std;

int start = 0, the_end = 0, search = 0, perestanovka = 0, srav = 0;

template<class T>

void DownHeap(T m[], int k, int n)
{
	T new_el;
	int child;
	new_el = m[k];

	while (k <= n / 2)
	{
		child = 2 * k;
		srav++;
		if (child < n && m[child] < m[child + 1])
		{
			child++;
		}
		srav++;
		if (new_el >= m[child])
		{
			break;
		}

		m[k] = m[child];
		perestanovka++;
		k = child;
	}
	perestanovka++;

	m[k] = new_el;
}

template<class T>

void DownHeap_v2(T m[], int kol, int n)
{
	int nom = 0;
	while (kol >= 3)
	{
		if (kol % 2 == 1)
		{
			nom = (kol - 1) / 2;
		}
		else
		{
			nom = (kol - 2) / 2;
		}
		srav++;
		if (m[kol] > m[nom])
		{
			cout << "�������� ������� ��������: " << m[kol] << " � " << m[nom] << endl;
			swap(m[kol], m[nom]);
			perestanovka++;
		}
		kol = nom;
	}
	srav++;
	if (m[1] > m[0] && m[1] > m[2])
	{
		cout << "�������� ������� ��������: " << m[1] << " � " << m[0] << endl;
		swap(m[1], m[0]);
		perestanovka++;
	}
	srav++;
	if (m[2] > m[0] && m[2] > m[1])
	{
		cout << "�������� ������� ��������: " << m[2] << " � " << m[0] << endl;
		swap(m[2], m[0]);
		perestanovka++;
	}
}

template<class T>

void HeapSort(T m[], int n)
{
	int i, kol = 0;
	cout << "1 ���� ����������: ���������� �������� '������-����'" << endl << endl;
	if (n >= 3)
	{
		cout << "�������� �������� �� ���� ���������: " << m[0] << ", " << m[1] << " � " << m[2] << endl;
		srav++;
		if (m[1] > m[0] && m[1] > m[2])
		{
			cout << "�������� ������� ��������: " << m[1] << " � " << m[0] << endl;
			swap(m[1], m[0]);
			perestanovka++;
		}
		srav++;
		if (m[2] > m[0] && m[2] > m[1])
		{
			cout << "�������� ������� ��������: " << m[2] << " � " << m[0] << endl;
			swap(m[2], m[0]);
			perestanovka++;
		}
		cout << "������� ������: ";
			for (int k = 0; k < n; k++)
			{
				cout << m[k] << " ";
			}
			cout << endl;
		for (i = 3; i < n; i++)
		{
			cout << endl << "������� ����� ������� � �������� " << m[i] << endl;
			DownHeap_v2(m, i, n - 1);
			cout << "������� ������: ";
			for (int k = 0; k < n; k++)
			{
				cout << m[k] << " ";
			}
			cout << endl;
		}
	}
	cout << endl << "2 ���� ����������: ���������� ���������� " << endl << endl;
	for (i = n - 1; i > 0; --i)
	{
		cout << "�������� ������� ��������: " << "�������� ������� ( " << m[0]
				<< " ) � " << " ����� �������� �������, ������� ����� ����� ��� ��������������� ������ ( " << m[i] << " )" << endl << endl;
		swap(m[i], m[0]);
		perestanovka++;
		cout << "������ ���� '��������' �������, ����� ��� ����������� � ��� �������� ������������� ����������� ��������" << endl;
		DownHeap(m, 0, i - 1);
			cout << "������� ��������������� ������: ";
			for (int k = 0; k < n; k++)
			{
				cout << m[k] << " ";
			}
			cout << endl << endl;
	}
}

template<class T>

void HeapSort_var2(T m[], int n)
{
	int i, kol = 0;
	if (p == 1)
	cout << "1 ���� ����������: ���������� �������� '�����-�����'" << endl;
	for (i = n / 2 - 1; i >= 0; --i)
	{
	cout << endl << "������� ����� ������� � �������� " << m[i] << endl;
	DownHeap(m, i, n - 1);
	cout << "������� ������: ";
	for (int k = 0; k < n; k++)
	{
		cout << m[k] << " ";
	}
	cout << endl;
	
	}
	cout << endl << "2 ���� ����������: ���������� ���������� " << endl << endl;
	for (i = n - 1; i > 0; --i)
	{
		cout << "�������� ������� ��������: " << "�������� ������� ( " << m[0]
				<< " ) � " << " ����� �������� �������, ������� ����� ����� ��� ��������������� ������ ( " << m[i] << " )" << endl << endl;
		swap(m[i], m[0]);
		perestanovka++;
		cout << "������ ���� '��������' �������, ����� ��� ����������� � ��� �������� ������������� ����������� ��������" << endl;
		DownHeap(m, 0, i - 1);
		cout << "������� ��������������� ������: ";
		for (int k = 0; k < n; k++)
		{
			cout << m[k] << " ";
		}
		cout << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, var;
	cout << "������� ������ �������: ";
	cin >> n;
	cout << "���� ����� ������� �������� '������-����', �� ������� '0', " << endl <<
		"����� �������� ����� ��������� '�����-�����' ";
	cin >> var;
	if (var != 0)
	{
		var = 1;
	}
	cout << endl;
	cout << "��������� ������: " << endl;
	int *mas = new int[n];
	\\srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 2000 - 1000;
		cout << mas[i] << " ";
	}
	cout << endl << endl;
	if (var == 0)
	{
		start = clock();
		HeapSort(mas, n);
		the_end = clock();
	}
	else
	{
		start = clock();
		HeapSort_var2(mas, n);
		the_end = clock();
	}
	search = the_end - start;
	cout << endl;
	cout << "��������������� ������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl << endl;
	cout << "����� ����������� �� ����������: " << search << " ��" << endl << endl;
	cout << "���������� ���������: " << srav << endl << endl;
	cout << "���������� ������������: " << perestanovka << endl << endl;
	system("pause");
	return 0;
}



