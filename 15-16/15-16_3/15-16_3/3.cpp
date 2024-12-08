#include <iostream>
using namespace std;


void vvod_chisel(float massiv_dannih[], int size)
{
	cout << "\n\nVvedite chisla s 1-go po " << size << "\n\n";

	for(int i = 0; i < size; i++)
	{
		cin >> massiv_dannih[i];
		cout << "\n";
	}
}


void processe(float massiv_dannih[], int size)
{
	float sum = 0, mult = 1;
	for (int i = 0; i < size; i++)
	{
		if ((massiv_dannih[i] >= 0) && ( ((int)massiv_dannih[i]) %2 == 0))
		{
			sum = sum + massiv_dannih[i];
			mult = mult*massiv_dannih[i];
		}
	}

	cout << "\n\nSumma = " << sum;
	cout << "\n\nProizvedenie = " << mult;
}



void main()
{
	int size;
	cout << "\n\nVvedite kolichestvo simvolov  ";
	cin >> size;
	float *data_base = new float(size); 

	cout << "\n\n\n";
	vvod_chisel(&data_base[0], size);

	processe(&data_base[0], size);


	cout << "\n\n\n";
	system("pause");
}