/*Программа проходит по всем элементами массива по порядку.
  Каждый текущий элемент сравнивается с соседним и, если он   
  меньше/больше(если сортируем по убыванию/возрастанию соответственно)
  меняется местами с соседним.*\
 
 
#include<iostream>
 
using namespace std;


void bubble_sort(int* mass, int n){//time->O(n^2)
	for(int i = 1; i < n; ++i)
	{
		for(int r = 0; r < n-i; r++)
		{
			if(mass[r] > mass[r+1])
			{
				// Обмен местами
				int temp = mass[r];
				mass[r] = mass[r+1];
				mass[r+1] = temp;
			}
		}
	}
}
 
int main()
{
	/* Установим размер массива */
	int n; // Кол-во элементов
	cout << "razmer massiva: ";
	cin >> n; 
	
	/* Заполним массив значениями */
	int mass[n];
	for(int i = 0; i < n; ++i)
	{
		cout << "arr["<<i<<"]: ";
		cin >> mass[i]; 
	} 
	
	/* Выведем исходный массив */
	cout << "arr: ";
	for(int i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	
    bubble_sort(mass,n);
	
	/* Выведем отсортированный массив */
	cout << "arr_new: ";
	for(int i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	
	
	
	return 0;
}
