#include <iostream>
using namespace std;


void main()
{
	float time;
	cout << "\n\nVvedite tekuschee vremia  ";
	cin >> time;


	if (time <= 6)
		cout << "\n\n Noch";
	else
		if (time <= 12)
			cout << "\n\nUtro";
		else
			if (time <= 18)
				cout << "\n\nDen";
			else
				if (time <= 23)
					cout << "\n\nVecher";

	cout << "\n\n\n";
	system("pause");
}