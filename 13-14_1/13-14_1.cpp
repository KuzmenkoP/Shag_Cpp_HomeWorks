#include <iostream>
using namespace std;


void func_proverka_na_chetnost(int CHISLO)
{
	if ( CHISLO % 2 )
		cout << "\n\nChislo  " << CHISLO << "  ne chetnoe";
	else
		cout << "\n\nChislo  " << CHISLO << "  chetnoe";
	return ;
}


void main()
{
	float chislo;

	
		
	cout << "\n\nVvedite CELOE chislo dlia proverki chetnosti: ";
	cin >> chislo;
	
	if ((chislo - (int) chislo))
	{
			cout << "\n\nVvedennoe chislo ne celoe ";
			
			cout << "\n\n\n";
			system("pause");
			exit (0);
	}


	func_proverka_na_chetnost(chislo);

	cout << "\n\n\n";
	system("pause");
}