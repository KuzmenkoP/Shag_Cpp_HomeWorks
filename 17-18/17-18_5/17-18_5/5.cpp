#include <iostream>
using namespace std;


void main()
{
	int kol_tovara;
	cout << "\n\nVvedite kolichestvo tovara  ";
	cin >> kol_tovara;

	float stoimost;
	cout << "\n\nVvedite stoimost za edinicu tovara ";
	cin >> stoimost;

	float summa;
	summa = stoimost*kol_tovara;
	
	if (summa >= 300 ) cout << "\n\nStoimost s uchetom skidki v 7% sostavliaet  " << summa - summa*0.07;
	else
		if (summa >= 200 ) cout << "\n\nStoimost s uchetom skidki v 5% sostavliaet  " << summa - summa*0.05;
		else
			if (summa >= 100 ) cout << "\n\nStoimost s uchetom skidki v 3% sostavliaet  " << summa - summa*0.03;
			else cout << "\n\nStoimost sostavliaet  " << summa;


	cout << "\n\n\n";
	system("pause");
}