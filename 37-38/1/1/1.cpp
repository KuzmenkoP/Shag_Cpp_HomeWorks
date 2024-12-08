#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


void main()
{
	srand(time(NULL));
	const int sizeX = 5, sizeY = 5;
	int mass[sizeX][sizeY], buff = 0;


	cout << "\n\n\n";
	for(int i = 0;i<sizeX; i++)
	{
		cout << "\n";
		for(int j = 0; j< sizeY; j++)
		{
			mass[i][j] = rand()%10;
			cout << mass[i][j] << "  ";

			if(!mass[i][j]) buff++;
		}
		
	}

	
/*
	cout << "\n\n\n";
	for(int i = 0;i<size; i++)
	{
		cout << mass[i] << "  ";
	}
	*/
	cout << "\n\nKolichestvo elementov 0  = " << buff;
	cout << "\n\n\n";
	system("pause");
}