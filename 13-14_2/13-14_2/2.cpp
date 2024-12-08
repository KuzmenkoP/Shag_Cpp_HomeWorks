#include <iostream>
using namespace std;


void func_sravnenie(float a,float b)
{
	float bolshee, menshee;
	bolshee = a * b;
	menshee = (a + b)/2;


	if ( a > b )
	{			
			a=bolshee;
			b=menshee;
			cout << "\n\nBolshee chislo A\nMenshee chislo B";

			cout << "\nProizvedenie zapisanno v A = " << a;
			cout << "\n\nPolusumma zapisannaia v B = " << b;
			
			
	}
	else
	{
		if (a != b)
		{
				b=bolshee;
				a=menshee;
			cout << "\n\nMenshee chislo A\nBolshee chislo B";

			cout << "\n\nPolusumma zapisannaia v A = " << a;
			cout << "\nProizvedenie zapisanno v B = " << b;
			
		}
		else
		{
			cout << "\n\n\nChislo A sovpadaet s chislom B";
		}
	}
}



void main()
{
	float a, b;
	
	cout << "\n\nVvedite chislo a : ";
	cin >> a;
	
	cout << "\n\nVvedite chislo b : ";
	cin >> b;

	func_sravnenie(a, b);

	cout << "\n\n\n";
	system("pause");
}