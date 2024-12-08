#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


void main()
{
	srand(time(NULL));
	const int size = 10;
	int mass[size];


	cout << "\n\n\n";
	for(int i = 0;i<size; i++)
	{
		mass[i] = (-rand()%(41))+20;
		cout << mass[i] << "  ";
	}

	int polog_poz, max;
	max = mass[0];
	for(int i = 0; i<size; i++)
	{
		if(mass[i] >= max)
			{
				polog_poz = i;
				max = mass[i];
				
			}
	
	}


	int otr_poz, min;
	min = mass[0];
	for(int i = 0; i<size; i++)
	{
		if(mass[i] <= min)
			{
				otr_poz = i;
				min = mass[i];
				
			}
	
	}
	

	cout << "\n\nPozicia pologitelnogo chisla =  " << polog_poz;
	cout << "\n\nPozicia otridcatelnogo chisla =  " << otr_poz;

	int tmp;
	if(otr_poz > polog_poz)
	{
		tmp = otr_poz;
		otr_poz = polog_poz;
		polog_poz = tmp;
	}

	for(int i = otr_poz+1; i<polog_poz-1; i++)
	{
		for(int j = i+1; j<polog_poz-1; j++)
		{
			if(mass[j]>=mass[i])
			{
				tmp = mass[j];
				mass[j] = mass[i];
				mass[i] = tmp;
			}
			
		}
		
	}

	cout << "\n\n\n";
	for(int i = 0;i<size; i++)
	{
		cout << mass[i] << "  ";
	}

	cout << "\n\n";
	cout << "\n\n\n";
	system("pause");
}