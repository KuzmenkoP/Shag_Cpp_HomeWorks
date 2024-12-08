#include <iostream>
using namespace std;

class vector
{
	int *mass;
	int cnt_elem;
public:
	vector(int cnt)
	{
		mass = new int[cnt];
		cnt_elem = 0;
	}

	vector(const vector &obj)
	{
		this->mass = mass;
	}

	~vector()
	{
		delete mass;	
	}

	void input_elem(int elem)
	{
		mass[cnt_elem] = elem;
		cnt_elem++;
	}

	void out_elem(int number)
	{
		if (number > cnt_elem) cout << "\nElement otsutstvuet";
		cout << "\n\nElement " << number << " raven " << mass[number];
	}
};

void main()
{
	int CNT;
	cout << "\n\nVvedite razmer massiva  ";
	cin >> CNT;
	vector obj(CNT);
	//obj = new vector(CNT);
	int data;
	for(int i = 0; i< CNT; i++)
	{
	cout <<"\nVvedite element ";
	cin >> data;
	obj.input_elem(data);
	}
	
	for(int i = 0; i< CNT; i++)
	{
	cout <<"\n\nElement ";
	obj.out_elem(i);
	}
	



	cout << "\n\n\n";
	system("pause");
}