#include <iostream>
#include <string.h>

using namespace std;

void main()
{
	int size;
	int bilet_size;
	
	cout << "\n\nVvedite kolichestvo cifr nomera bileta   ";
	cin >> size;
	size++;

	char *n_bileta = new char[size];

	
	cout << "\n\nVvedite nomer bileta   ";
	cin >> n_bileta;


	for(int i = 0; i < size; i++)
	{
		if (n_bileta[i]==NULL)
			{
				bilet_size = i-1;
				break;
			}
	}

	if ( (n_bileta[0] == n_bileta[bilet_size]) && (n_bileta[1] == n_bileta[bilet_size-1]))
		cout << "\n\n\nVash bilet schastlivii";
	else 
		cout << "\n\n\nVash bilet ne schastlivii";


	cout << "\n\n\n";
	system("pause");
}