#include <iostream>
using namespace std;

void main()
{
	int chislo;
	cout << "\n\nVvedite chislo  ";
	cin >> chislo;

	int n_cifr = 0, ostatok = chislo;
	float summa = 0;
	for (;ostatok > 0 ;n_cifr++)
	{
		summa = summa + ostatok%10;
		ostatok = ostatok/10;
	
	}


	
	cout << "\n\nKolichestvo cifr v chisle  =  " << n_cifr;
	cout << "\n\nSumma cifr  =  " << summa;

	ostatok = chislo;
	cout << "\n\nObratnoe chislo  =  ";
	for (int i = 1; i<= n_cifr; i++)
	{
		cout << ostatok%10;
		ostatok = ostatok/10;
	}
	
	cout << "\n\n\n";
	system("pause");
}