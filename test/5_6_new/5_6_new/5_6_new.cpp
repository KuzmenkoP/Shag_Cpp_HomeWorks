#include <iostream>
#include <string.h>
using namespace std;

class student
{
	char *name;
	int age;
	char *pol;
	int phone;
public:
	student()
	{

	}

	student(const student &obj)
	{
		this->name = name;
		this->age = age;
		this->pol = pol;
		this->phone = phone;
	}




	~student()
	{

	}

	void input_name(char *student_name)
	{
		int cnt;
		cnt = strlen(student_name);
		name = new char[cnt];
		strcpy(name, student_name);
	}

	void output_name()
	{
		cout << "\n\nName  " << name;
	}


	void input_age(int student_age)
	{
		age = student_age;
	}

	void output_age()
	{
		cout << "\n\nAge  " << age;
	}

	
	void input_pol(char *student_pol)
	{
		int cnt;
		cnt = strlen(student_pol);
		pol = new char[cnt];
		strcpy(pol, student_pol);
	}

	void output_pol()
	{
		cout << "\n\nPol  " << pol;
	}
	
	
	void input_phone(int student_phone)
	{
		phone = student_phone;
	}

	void output_phone()
	{
		cout << "\n\nPhone  " << phone;
	}
};

void main()
{
	student *obj;
	obj = new student;

	cout << "\n\nVvedite imia  ";
	char *name_stud = new char[25];
	cin >> name_stud;

	cout << "\n\nVvedite vozrast  ";
	int age_stud;
	cin >> age_stud;

	cout << "\n\nVvedite pol  ";
	char *pol_stud = new char[10];
	cin >> pol_stud;

	cout << "\n\nVvedite telefonnii nomer  ";
	int phone_stud;
	cin >> phone_stud;

	obj->input_name(name_stud);
	obj->input_age(age_stud);
	obj->input_pol(pol_stud);
	obj->input_phone(phone_stud);

	obj->output_name();
	obj->output_age();
	obj->output_pol();
	obj->output_phone();


cout << "\n\n\n";
system("pause");
}
