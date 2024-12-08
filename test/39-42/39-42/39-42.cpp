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
		//	������ ���������� �� ������
			int **str;
			str = (int **) new int[n_str];

		//	������ �������� �����
			for(int i = 0; i < n_str; i++)
			{
				str[i] = new int[n_stb];
			}
		elem00 = str;
	}
	
	void add_all_elem()
	{
		//	������ ��������� � ������

		for(int i = 0; i < n_str; i++)
		{
			for (int j = 0; j < n_stb; j++)
			{
				cout << "\n������� �������  [ " << i << " ]  [ " << j << " ]  �������  " ;
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

		// ������ ������� ���������� ����� � ��������
			int temp;
			temp = n_str;
			n_str = n_stb;
			n_stb = temp;

		//	�������� ��� ����������������� ������� �� ����� ��������� ���������� ����� � ��������
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
			cout << "\n\n������������ ����� ����� ������ ��� ���������� �������";
			return NULL;
		}

		int tmp, mult = 1, prev_mult = 0;
		int positive, negative;

		//	������� ����� ������������ ������ ����������
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


		
	

		//	������� ����� ������������ �������� ����������
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
			cout << "\n\n����������� ��������. ������� �� ����";
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


//	�������� �������
//==================================================================================
	cout << "\n\n������� ����������� �������\n\n������� ���������� �����  ";
	int stroki, stolbci;
	cin >> stroki;
	
	cout << "\n\n������� ���������� ��������  ";
	cin >> stolbci;

	matrix obj(stroki,stolbci);
	obj.out_matrix();
	
//==================================================================================
/*
	cout << "\n\n����������������� �������\n";
	obj.transp();
	obj.out_matrix();
*/
/*
	cout << "\n\n������������ ������� �� �����\n";
	cout << "\n������� �����  ";
	int tmp;
	cin >> tmp;

	obj.mult_n(tmp);
	obj.out_matrix();
*/
/*
	cout << "\n\n����� ������� � ������\n";
	cout << "\n������� �����  ";
	cin >> tmp;

	obj.summ_n(tmp);
	obj.out_matrix();
*/
	
	
	cout << "\n\n--->  " << obj.opr();

	cout << "\n\n\n";
	system("pause");
}