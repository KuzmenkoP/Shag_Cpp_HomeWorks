#include <iostream>
using namespace std;

float stoimost (int n_punkta, int KOL_BILETOV)
{
	float st_bileta;
	switch (n_punkta)
	{
	case 1:
		st_bileta = 22;
		break;
	
	case 2:
	case 3:
	case 4:
		st_bileta = 25;
		break;
	
	case 5:
	case 6:
		st_bileta = 30;
		break;
	
	case 7:
	default:
		st_bileta = 30;
		break;
	
	}

	return st_bileta * KOL_BILETOV;

}

void main()
{
	int n_punkta;
	cout << "\n\nVvedite nomer naselennogo punkta  ";
	cin >> n_punkta;

	int kol_biletov;
	cout << "\n\nVvedite kolichestvo biletov  ";
	cin >> kol_biletov;
	
	cout << "\n\nStoimost " << kol_biletov << " biletov k naselennomu punktu " << n_punkta << "  =  " << stoimost(n_punkta, kol_biletov);
	cout << "\n\n\n";
	system("pause");
}