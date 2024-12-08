#include <iostream>
using namespace std;

const int NAME_SIZE = 15, DATA_SIZE = 2;

struct videomagazin
{
	char film_name[NAME_SIZE];
	char rejiser[NAME_SIZE];
	char janr[NAME_SIZE];
	int reiting;
	float price;
};
videomagazin data_base[DATA_SIZE];
videomagazin blok;


	
videomagazin poisk(char menu[DATA_SIZE], char name[NAME_SIZE])
{
	
}







void main()
{

	unsigned int vibor_menu;
	char name[NAME_SIZE];

	cout << "\n\n\t\tMain menu\n\n\t1 -- Poisk filma po nazvaniu\n\t2 -- Poisk filma po janru\n\t3 -- Poisk filma po rejiseru\n\t4 -- Poisk samogo populiarnogo filma v janre\n\t5 -- Pokazat vse zapisi i dobavlenie novoi zapisi";
	cin >> vibor_menu;

	
	switch (vibor_menu)
	{
		case 1:
			cout << "\n\nVvedite nazvanie filma dlia poiska\t---\t";
			cin >> blok.film_name;
			poisk( blok.film_name, name); // Поиск по названию
			break;
		
		case 2:
			cout << "\n\nVvedite janr filma dlia poiska\t---\t";
			cin >> blok.janr;
			poisk(blok.janr); // Поиск по жанру
			break;

		case 3:
			cout << "\n\nVvedite imia rejisera filma dlia poiska\t---\t";
			cin >> blok.rejiser;
			poisk(blok.rejiser); // Поиск по режисёру
			break;
		
		case 4:
			cout << "\n\nSamii populiarnii film\n\n";
			poisk(vibor_menu, );
			break;
		
		case 5:
			cout << "\n\nVse zapisi\n\n";
			viv_vseh_zapisei();

			cout << "\n\nSozdanie novoi zapisi\n\n";
			sozd_zapisi();
			break;
	}



	cout << "\n\n\n";
	system("pause");
}
