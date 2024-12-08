#include <iostream>
using namespace std;

void main()
{
	const int size = 10;
	int mass[size];

	cout << "\n\n";
	for (int i = 0; i< size; i++)
	{
		cout << "\nVvedite " << i << "-ii element massiva  ";
		cin >> mass[i];
	}

	
	cout << "\n\n\n";
	for(int i = 0; i< size; i++)
	{
		cout <<" " << mass[i];
	}


	int buff;
	for (int i = 0; i < size/2; i++)
	{
		buff = mass[i];
		mass[i] = mass[(size - i-1)];
		mass[(size - i-1)] = buff;
	}

	cout << "\n\n\n";
	for(int i = 0; i< size; i++)
	{
		cout <<" " << mass[i];
	}


	cout << "\n\n\n";
	system("pause");
}