#include <iostream>
using namespace std;

void func_perevoda(int chislo, int osnovanie)
{
	int mass[8] = {0};
	int ostatok = 0, celaia_chast = 0;
	int i;
	celaia_chast = chislo;


	switch (osnovanie)
	{
		case 8:
			cout << "\n\nZnacenie  = " << chislo/osnovanie << chislo%osnovanie;
		break;

		case 2:
			
			for (i = 0;celaia_chast != 1; i++)
			{
				ostatok = celaia_chast % osnovanie;
				celaia_chast = celaia_chast / osnovanie;
				mass[i] = ostatok;
			}
			mass[i] = 1;

			cout << "\n\n";
			for(int i = 7; i>=0; i--)
			{
				cout << mass[i] << " ";
			}
		break;

		case 16:
			char massiv[6] = {'A','B','C','D','E','F'};
			cout << "\n\nZnacenie  = " << chislo/osnovanie << massiv[6-(chislo%(16))];
		break;
		


	}
	
} 


void main()
{
	int chislo;
	cout << "\n\nVvedite celoe pologitelnoe desiatichnoe chislo  ";
	cin >> chislo;

	int osnovanie;
	cout << "\n\nVvedite sistemu schislenia (2,8,16)  ";
	cin >> osnovanie;

	func_perevoda(chislo, osnovanie);

	cout << "\n\n\n";
	system("pause");
}