// 4sem1lab.cpp: определяет точку входа для консольного приложения.
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
			cout << "Поменяем местами элементы: " << m[kol] << " и " << m[nom] << endl;
			swap(m[kol], m[nom]);
			perestanovka++;
		}
		kol = nom;
	}
	srav++;
	if (m[1] > m[0] && m[1] > m[2])
	{
		cout << "Поменяем местами элементы: " << m[1] << " и " << m[0] << endl;
		swap(m[1], m[0]);
		perestanovka++;
	}
	srav++;
	if (m[2] > m[0] && m[2] > m[1])
	{
		cout << "Поменяем местами элементы: " << m[2] << " и " << m[0] << endl;
		swap(m[2], m[0]);
		perestanovka++;
	}
}

template<class T>

void HeapSort(T m[], int n)
{
	int i, kol = 0;
	cout << "1 этап сортировки: Построение пирамиды 'сверху-вниз'" << endl << endl;
	if (n >= 3)
	{
		cout << "Образуем пирамиду из трех элементов: " << m[0] << ", " << m[1] << " и " << m[2] << endl;
		srav++;
		if (m[1] > m[0] && m[1] > m[2])
		{
			cout << "Поменяем местами элементы: " << m[1] << " и " << m[0] << endl;
			swap(m[1], m[0]);
			perestanovka++;
		}
		srav++;
		if (m[2] > m[0] && m[2] > m[1])
		{
			cout << "Поменяем местами элементы: " << m[2] << " и " << m[0] << endl;
			swap(m[2], m[0]);
			perestanovka++;
		}
		cout << "Получим массив: ";
			for (int k = 0; k < n; k++)
			{
				cout << m[k] << " ";
			}
			cout << endl;
		for (i = 3; i < n; i++)
		{
			cout << endl << "Добавим новый элемент в пирамиду " << m[i] << endl;
			DownHeap_v2(m, i, n - 1);
			cout << "Получим массив: ";
			for (int k = 0; k < n; k++)
			{
				cout << m[k] << " ";
			}
			cout << endl;
		}
	}
	cout << endl << "2 этап сортировки: Собственно сортировка " << endl << endl;
	for (i = n - 1; i > 0; --i)
	{
		cout << "Поменяем местами элементы: " << "корневой элемент ( " << m[0]
				<< " ) и " << " самый конечный элемент, который стоит перед уже отсортированной частью ( " << m[i] << " )" << endl << endl;
		swap(m[i], m[0]);
		perestanovka++;
		cout << "Теперь надо 'просеять' элемент, чтобы все находящиеся в нем элементы удовлетворяли определению пирамиды" << endl;
		DownHeap(m, 0, i - 1);
			cout << "Получим отсортированный массив: ";
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
	cout << "1 этап сортировки: Построение пирамиды 'снизу-вверх'" << endl;
	for (i = n / 2 - 1; i >= 0; --i)
	{
	cout << endl << "Добавим новый элемент в пирамиду " << m[i] << endl;
	DownHeap(m, i, n - 1);
	cout << "Получим массив: ";
	for (int k = 0; k < n; k++)
	{
		cout << m[k] << " ";
	}
	cout << endl;
	
	}
	cout << endl << "2 этап сортировки: Собственно сортировка " << endl << endl;
	for (i = n - 1; i > 0; --i)
	{
		cout << "Поменяем местами элементы: " << "корневой элемент ( " << m[0]
				<< " ) и " << " самый конечный элемент, который стоит перед уже отсортированной частью ( " << m[i] << " )" << endl << endl;
		swap(m[i], m[0]);
		perestanovka++;
		cout << "Теперь надо 'просеять' элемент, чтобы все находящиеся в нем элементы удовлетворяли определению пирамиды" << endl;
		DownHeap(m, 0, i - 1);
		cout << "Получим отсортированный массив: ";
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
	cout << "Введите размер массива: ";
	cin >> n;
	cout << "Если нужно строить пирамиду 'сверху-вниз', то введите '0', " << endl <<
		"иначе пирамида будет построена 'снизу-вверх' ";
	cin >> var;
	if (var != 0)
	{
		var = 1;
	}
	cout << endl;
	cout << "Начальный массив: " << endl;
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
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl << endl;
	cout << "Время затраченное на сортировку: " << search << " мс" << endl << endl;
	cout << "Количество сравнений: " << srav << endl << endl;
	cout << "Количество перестановок: " << perestanovka << endl << endl;
	system("pause");
	return 0;
}



