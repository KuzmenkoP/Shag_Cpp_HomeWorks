#include <iostream>
using namespace std;


void main()
{
	float *otcenka = new float[4];
	cout << "\n\nVvedite normi:\n\n5 ballov  -  ";
	cin >> otcenka[3];
	cout << "\n4 balla   -  ";
	cin >> otcenka[2];
	cout << "\n3 balla   -  ";
	cin >> otcenka[1];
	cout << "\n 2 balla   -  ";
	cin >> otcenka[0];

	float prijok;
	cout << "\n\nVvedite dannie o prijke  ";
	cin >> prijok;
	
	if (prijok >= otcenka[3])
		cout << "\n\nOtcenka 5 (otlichno)";
	else
		if (prijok >= otcenka[2])
			 cout << "\n\nOtcenka 4 (horosho)";
		else
			if (prijok >= otcenka[1])
				cout << "\n\nOtcenka 3 (ploho)";
			else
				cout << "\n\nOtcenka 2 (ne sdal)";				
				

	cout << "\n\n\n";
	system("pause");
}