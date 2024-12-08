#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


void sortirovka(int massiv[],int SIZE, int sort_po_ubivaniu)
{
	int buffer;

	if (sort_po_ubivaniu)
	{
		for (int i = 0; i<(SIZE-1); i++)
		{
			for(int j = i+1; j<SIZE;j++)
			{
				if (massiv[j] > massiv[i])
				{
					buffer = massiv[i];
					massiv[i] = massiv[j];
					massiv[j] = buffer;
				}
			}
		}
	}

	else
	{
		for (int i = SIZE-1; i>0; i--)
		{
			for(int j = i-1; j>=0;j--)
			{
				if (massiv[j] > massiv[i])
				{
					buffer = massiv[i];
					massiv[i] = massiv[j];
					massiv[j] = buffer;
				}
			}
		}
	}	
}


void main()
{
	const int size = 10;
	bool sort_po_ubivaniu;
	cout << "\n\nVvedite napravlenie sortirovki (1 - po ubivaniu, 0 - po vozrastaniu) ";
	cin >> sort_po_ubivaniu;

	srand(time(NULL));
	int mass[size];
	cout << "\n\n\n";
	for (int i = 0; i<size; i++)
	{
		mass[i] = rand()%11;
		cout << mass[i] << "  ";
	}
	cout << "\n\n\n";

	sortirovka(mass,size, sort_po_ubivaniu);

	for (int i = 0; i<size; i++)
	{
		cout << mass[i] << "  ";
	}

	cout << "\n\n\n";
	system("pause");
}