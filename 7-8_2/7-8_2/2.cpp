#include <iostream>
using namespace std;


float func_translate_a_to_b(float sum_A, float kurs_A_k_usd, float kurs_B_k_usd)
{
	return ( (sum_A / kurs_A_k_usd) * kurs_B_k_usd );
}


void main()
{
	float sum_uah,kurs_uah,kurs_usd = 1,kurs_euro,kurs_ru;
	
	cout << "\n\nVvedite kurs UAH k USD: ";
	cin >> kurs_uah;
	cout << "\n\nVvedite kurs EURO k USD: ";
	cin >> kurs_euro;
	cout << "\n\nVvedite kurs RU k USD: ";
	cin >> kurs_ru;

	
	cout << "\n\nVvedite summu v UAH: ";
	cin >> sum_uah;
	
	cout << "\n\nSumma v USD = " << func_translate_a_to_b(sum_uah, kurs_uah, kurs_usd);
	cout << "\n\nSumma v EURO = " << func_translate_a_to_b(sum_uah, kurs_uah, kurs_euro);
	cout << "\n\nSumma v RU = " << func_translate_a_to_b(sum_uah, kurs_uah, kurs_ru);

	cout << "\n\n\n\t\"To be or not to be\"\n\t\t\\Shakespeare\\";
	
	cout << "\n\n\n";
	system("pause");
}