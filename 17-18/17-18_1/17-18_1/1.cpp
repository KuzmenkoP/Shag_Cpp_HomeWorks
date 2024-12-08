#include <iostream>
using namespace std;


void main()
{
	int mesiac;
	
	cout << "\n\nVvedite nomer mesiaca  ";
	cin >> mesiac;

	switch (mesiac)
	{
	case 1:
		cout << "\n\nJanvar";
		break;

	case 2:
		cout << "\n\nFevral";
		break;

	case 3:
		cout << "\n\nMart";
		break;

	case 4:
		cout << "\n\nAprel";
		break;

	case 5:
		cout << "\n\nMay";
		break;

	case 6:
		cout << "\n\nIun";
		break;

	case 7:
		cout << "\n\nIul";
		break;

	case 8:
		cout << "\n\nAvgust";
		break;

	case 9:
		cout << "\n\nSentiabr";
		break;

	case 10:
		cout << "\n\nOktiabr";
		break;

	case 11:
		cout << "\n\nNoiabr";
		break;

	case 12:
		cout << "\n\nDekabr";
		break;

	default:
		cout << "\n\nVvedennii nomer ne sovpadaet ni s odnim mesiacem";
		break;
	}
	
	cout << "\n\n\n";
	system("pause");
}