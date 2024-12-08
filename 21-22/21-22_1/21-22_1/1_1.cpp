#include <iostream>
using namespace std;


void main()
{
	char simvol;
	cout << "\n\nVvedite simvol  ";
	cin >> simvol;

	int kolichestvo;
	cout << "\n\nVvedite kolichestvo simvolov  ";
	cin >> kolichestvo;

	bool napravlenie;
	cout << "\n\nVvedite napravlenie linii\n\n0  -  gorizontalnaia\n1   -  vertikalnaia\n\n";
	cin >> napravlenie;

	while (kolichestvo >0)
	{
		if (napravlenie) cout << "\n" << simvol;
		else cout << "\ " << simvol;
		kolichestvo--;
	}


	cout << "\n\n\n";
	system("pause");
}