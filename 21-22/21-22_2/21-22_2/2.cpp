#include <iostream>
#include <cmath>
using namespace std;


void main()
{
	float a,b, tmp;
	cout << "\n\nVvedite diapazon\nA = ";
	cin >> a;
	cout << "\nB = ";
	cin >> b;

	if (a>b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	int i;
	if (fmod(a,2)) i = ((int)a) + 1;
	
	float buff = 0;
	while (i <= b)
	{
		if (i%2) buff = buff + i;
		i++;
	}

	cout << "\n\nSumma celih nechetnih chisel diapazona = " << buff;
	cout << "\n\n\n";
	system("pause");
}