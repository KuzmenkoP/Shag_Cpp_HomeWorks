#include <iostream>
using namespace std;


void main()
{
	float n;
	cout << "\n\nVvedite chislo N  ";
	cin >> n;

	if (n<0) cout << "\n\nVvedennoe chislo dolgno bit > 0";
	else
		if (n<1) cout << "\n\nFaktorial pologitelnih celih chisel  =  1";
		else
		{
			float factorial = 1;
			int buff = 1;
			
			while (buff <= n)
			{
				factorial = factorial * buff;
				buff++;
			}

			cout << "\n\nFactorial neotridcatelnih celih chisel  =  " << factorial;

		}
	
		cout << "\n\n\n";
	system("pause");
}