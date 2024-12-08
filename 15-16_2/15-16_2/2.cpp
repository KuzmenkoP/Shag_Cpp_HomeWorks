#include <iostream>
using namespace std;


void main()
{
	char key;
	
	

	float dlinna;
	double index;

	for(;;)
	{
		cout << "\n\n\n\tMain menu\n1 - perevod s duimov v cantimetri";
		cout << "\n2 - perevod s santimetrov v duimi";
		cout << "\n2 - perevod s A v B";
		cout << "\n0 - vihod\n\n";
		cin >> key;

		switch (key)
		{	
			case '1':
				cout << "\n\nVvedite dlinnu v duimah   ";
				cin >> dlinna;
				index = 1/2.54;
				cout << "\n\nDlinna v santimetrah = " << (dlinna/index);
			break;

			case '2':
				cout << "\n\nVvedite dlinnu v santimetrah   ";
				cin >> dlinna;
				index = 2.54;
				cout << "\n\nDlinna v duimah = " << (dlinna/index);
			break;

			case '0':
			exit (0);

			case '3':
				cout << "\n\nVvedite znachenie A   ";
				cin >> dlinna;
				cout << "\n\nVvedite index  ( B / A )   ";
				 cin >> index;
				cout << "\n\nZnachenie B = " << (dlinna * index);
			break;
		}
	}


	cout << "\n\n\n";
	system("pause");
}