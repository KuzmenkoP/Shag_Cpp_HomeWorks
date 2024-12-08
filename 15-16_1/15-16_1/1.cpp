#include <iostream>
using namespace std;



int opr_kol_cifr( float CHISLO)
{
	int temp;
	
	temp = (int)CHISLO;
	int i = 0;
	for (; temp > 0; i++)
	{
		temp = temp/10;
	}

	return i;
}


float opr_summi_cifr(float CHISLO)
{
	float temp = 0;
	int ostatok = (int)CHISLO;
	
	for (; ostatok > 0;)
	{
		temp = temp + ostatok % 10;
		ostatok = ostatok/10;
	}
	return temp;
}


void main()
{
	int size;
	float chislo;
	
	cout << "\n\nVvedite chislo  ";
	cin >> chislo;
	
	size = opr_kol_cifr(chislo);
	cout << "\n\nKolichestvo cifr v chisle =  " << size;

	cout << "\n\nSumma cifr v chisle =  " << opr_summi_cifr(chislo);

	cout << "\n\n\n";
	system("pause");
}