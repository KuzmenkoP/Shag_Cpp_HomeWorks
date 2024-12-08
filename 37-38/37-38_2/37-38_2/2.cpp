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
	for(int i = 0;i<sizeY; i++)
	{
		cout << "\n";
		for(int j = 0; j< sizeX; j++)
		{
			mass[i][j] = rand()%10;
			cout << mass[i][j] << "  ";

			if(((i<=sizeY/2) && (j<=sizeX/2)) || ((i<=sizeY/2) && (j>sizeX/2)))
			{
				if(mass[i][j] > buff) buff = mass[i][j];
			}
		}
		
	}

	
	

	cout << "\n\n\nNaibolshee iz sootvetstvuiuschei oblasti  = " << buff;

	cout << "\n\n\n";
	system("pause");
}