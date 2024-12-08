#include <iostream>
using namespace std;

class matrix
{
	int n_str;
	int n_stb;

	int **elem00;

//.....................................................................................
	void create_matrix()
	{
		//	Массив указателей на строку
			int **str;
			str = (int **) new int[n_str];

		//	Создаём элементы строк
			for(int i = 0; i < n_str; i++)
			{
				str[i] = new int[n_stb];
			}
		elem00 = str;
	}
	
	void add_all_elem()
	{
		//	Запись элементов в массив

		for(int i = 0; i < n_str; i++)
		{
			for (int j = 0; j < n_stb; j++)
			{
				cout << "\nВведите элемент  [ " << i << " ]  [ " << j << " ]  массива  " ;
				cin >> elem00[i][j];
			}

			
		}
	}
//.....................................................................................

public:
	//==================================================================================
	matrix(int N_STR, int N_STB)
	{
		n_str = N_STR;
		n_stb = N_STB;

		create_matrix();
		add_all_elem();
	}

	~matrix()
	{

	}
	//==================================================================================

	int* add_elem(int str, int stb, int data)
	{
		elem00[str][stb] = data;
	}
	
	void out_matrix()
	{
		for(int i = 0; i < n_str; i++)
		{
			cout << "\n";
			for(int j = 0; j < n_stb; j++)
			{
				cout << elem00[i][j] << "\t";
			}
		}
	}

	//.....................................................................................

	void transp()
	{
		int **tmp;
		tmp = elem00;

		int old_n_str, old_n_stb;
		old_n_str = n_str;
		old_n_stb = n_stb;

		// Меняем местами количество строк и столбцов
			int temp;
			temp = n_str;
			n_str = n_stb;
			n_stb = temp;

		//	Создаётся уже транспонированная матрица по новым значениям количества строк и столбцов
			create_matrix();


		for(int i = 0; i < old_n_str; i++)
		{
			for(int j = 0; j < old_n_stb; j++)
			{
				elem00[j][i] = tmp[i][j];
			}
		}

		delete []tmp;
	}

	int opr()
	{
		if(n_str != n_stb)
		{
			cout << "\n\nОпределитель можно найти только для квадратной матрици";
			return NULL;
		}

		int tmp, mult = 1, prev_mult = 0;
		int positive, negative;

		//	Подсчет суммы произведений прямых диагоналей
			for(int i = 0; i < n_str; i++)
			{
				mult = 1;
				for(int j = 0; j < n_stb; j++)
				{
					if ( ( i + j ) >= n_stb)
						mult = elem00[j+i-n_stb][j] * mult;
					else
						mult = elem00[j + i][j] * mult;
				}
				//tmp = mult;
				mult = mult + prev_mult;

				prev_mult = mult;
			}
		positive = mult;


		
	

		//	Подсчет суммы произведений обратных диагоналей
			tmp = 0;
			mult = 1;
			prev_mult = 0;
			
			for(int i = 0; i < n_str; i--)
			{
				mult = 1;
				for(int j = 0; j < n_stb; j--)
				{

					
					
					/*if ( ( i + j ) >= n_stb)
						mult = elem00[(i+j) - (n_stb-1)][j] * mult;
					else
						mult = elem00[(n_stb-1) - (i+j)][j] * mult;
					/*
					
						mult = elem00[n_stb -(j+i)][j] * mult;
					else
						mult = elem00[i][j + i] * mult;
					*/
				}
				//tmp = mult;
				mult = mult + prev_mult;

				prev_mult = mult;
			}
		negative = mult;

//		return (positive - negative);
		return (negative);

//		return NULL;
	}

	void mult_n(int n)
	{
		for(int i = 0; i < n_str; i++)
		{
			for(int j = 0; j < n_stb; j++)
			{
				elem00[i][j] = elem00[i][j] * n;
			}
		}
	}

	void devide_n(int n)
	{
		if(n == 0)
		{
			cout << "\n\nЗапрещённая операция. Деление на НОЛЬ";
			return;
		}

		for(int i = 0; i < n_str; i++)
		{
			for(int j = 0; j < n_stb; j++)
			{
				elem00[i][j] = elem00[i][j] / n;
			}
		}
	}

	void summ_n(int n)
	{
		for(int i = 0; i < n_str; i++)
		{
			for(int j = 0; j < n_stb; j++)
			{
				elem00[i][j] = elem00[i][j] + n;
			}
		}
	}

	void razn_n(int n)
	{
		for(int i = 0; i < n_str; i++)
		{
			for(int j = 0; j < n_stb; j++)
			{
				elem00[i][j] = elem00[i][j] - n;
			}
		}
	}

	void inverse()
	{
		for(int i = 0; i < n_str; i++)
		{
			for(int j = 0; j < n_stb; j++)
			{
				elem00[i][j] = elem00[i][j] * (-1);
			}
		}
	}

};


void main()
{
	setlocale(LC_ALL, "Russian");


//	Создание матрици
//==================================================================================
	cout << "\n\nВведите размерность матрици\n\nВведите количество строк  ";
	int stroki, stolbci;
	cin >> stroki;
	
	cout << "\n\nВведите количество столбцов  ";
	cin >> stolbci;

	matrix obj(stroki,stolbci);
	obj.out_matrix();
	
//==================================================================================
/*
	cout << "\n\nТранспонированная матрица\n";
	obj.transp();
	obj.out_matrix();
*/
/*
	cout << "\n\nПроизведение матрици на число\n";
	cout << "\nВведите число  ";
	int tmp;
	cin >> tmp;

	obj.mult_n(tmp);
	obj.out_matrix();
*/
/*
	cout << "\n\nСумма матрици с числом\n";
	cout << "\nВведите число  ";
	cin >> tmp;

	obj.summ_n(tmp);
	obj.out_matrix();
*/
	
	
	cout << "\n\n--->  " << obj.opr();

	cout << "\n\n\n";
	system("pause");
}