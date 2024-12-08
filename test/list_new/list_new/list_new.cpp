#include <iostream>
using namespace std;

struct node
{
	char *data;
	node *next;
};

class list
{
	node *head;
	node *hvost;
public:
	//	-----------------------------------------------
	//	--------------- CONSTRUCTOR -------------------
	//	-----------------------------------------------
	list()
	{
		head = NULL;
		hvost = NULL;
	}

	~list()
	{

	}
	//	-----------------------------------------------
	//	--------------- DESTRUCTOR --------------------
	//	-----------------------------------------------
		



	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	�������� �������� �� ��� �������
	//	--- 0 - ������������� ������� ��������
	void dell_node_pos(int position)
	{
		node *prev = NULL, *next = NULL, *dell_node = NULL;
		
		dell_node = find_position(position);

		//	�������� �� ������������� �������� � ��������� ��������
				//	������� � ��������� �������� �����������?
				if(dell_node == NULL)
				{
					cout << "\n\n������� � ��������� �������� �����������";
					return;
				}
		
		
		prev = find_position(position - 1);
		next = find_position(position + 1);
		//	prev - �������������� �������� ���?
				if(prev == NULL)
				//	��, ��������������� ������� �� ����������
				{
					head = next;
					delete dell_node;
					return;
				}
				else
				{
					prev->next = next;
				}

		//	next - ���������� �������� �� ����������
				if(next == NULL)
				//	��, ������� ������� ������� ������
				{
					prev->next = NULL;
					hvost = prev;
				}
		
		delete dell_node;
	}





	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	����� ���������� ���������� ��������� � ������
	int cnt_elem()
	{
		node *ukaz;
		ukaz = head;
		if(ukaz == NULL) return 0;
		
		int cnt = 1;
		while(ukaz->next != NULL)
		{
			ukaz = ukaz->next;
			cnt++;
		}
		return cnt;
	}

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	���������� �������� � �������� �������
	//	---	0 - ������������� ������� �������� ������
	node* add_node_position(node *element, int position)
	{
		node *prev = NULL, *next = NULL;
		
		
		//	������������� ������� �������� � ������ ����� �������� ������� ��������� �� �������
			if(position <= 0)
				{
					position=0;
					next = find_position(position);
					head = element;
					element->next = next;

					return element;
				}

		//	������� ������������ �������� ������ ������� �������� �������� ������
			if(position >= cnt_elem())
			{
				add_node_end(element);
				return element;
			}

		//	������� ������� ��������� � ������ � ��������
			prev = find_position(position-1);
			next = find_position(position);

			prev->next = element;
			element->next = next;

			return element;
	}

	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	����� �������� �� �������� �������
	//	---	0	- ������������� ������� �������� ������
	//	--- NULL- ������������ ������� ���������� �������� � ��������������� �������� 
	node* find_position(int position)
	{
		node *ukaz;
		ukaz = head;

		//	�������� �� ���������� �� ��������� �������
				//	���� ������ ���� ���������� NULL
				if(ukaz == NULL) return NULL;
		
				//	���� ������� �������� ������ �������� �������� ������ ���������� NULL
				if( (position >= cnt_elem()) || (position < 0) ) return NULL;

		//	�� ��, ������� ��������� �� ������������ ������� ������
				for (int i = 1; i <= position; i++)
				{
					ukaz = ukaz->next;
				}

		return ukaz;
	}

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	����� ����� ������
	//	--- 0 - ������������� ������� �������� ������
	void print_all()
	{
		//	������ ����?
		if (head == NULL)
		//	��, ������ ����
		{
			cout << "\n\n������ ����";
			return;
		}

		//	���, ������ �� ����
		node *ukaz;
		ukaz = head;

		int i = 0;			//	����� ��������, ������������ ������ ��� ������ �� �����
		cout << "\n������� ������ " << i << "  " << ukaz->data;

		

		while(ukaz != hvost)
		{
			ukaz = ukaz->next;
			i++;
			cout << "\n������� ������ " << i << "  " << ukaz->data;
		}
		return;
	};

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	����� ������ �� �������
	//	--- 0 - ������������� ������� �������� ������
	void print_position(int position)
	{
		node *tmp;
		tmp = find_position(position);
		if (tmp == NULL)
		{
			cout << "\n\n������� � ��������� �������� �� ����������";
			return;
		}			
			
		cout << "\n������� ������ " << position << "  " << tmp->data;
		return;
	}


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	���������� �������� � ����� ������
	node* add_node_end(node *element)
	{
		//	������ ����?
		if (head == NULL)
		//	��, ������ ����
		{
			hvost = element;
			head = element;
		}
		
		//	���, ������ �� ����
		else
		{
		hvost->next = element;	//	��������� NEXT ���������� �������� ������ ������������� �� ����� �������
		hvost = element;
		}

		element->next = NULL;	//	�������� ���� NEXT ������ ��������
		
		return element;
	}
};

//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
//	������� �������� �������� ������ ��� ���������� ������� � ������
node* creating_node()
{
	//	�������� �������� ������	-------
	node *elem_spiska;
	elem_spiska = new node;

	//	���� ������		- - - -
	elem_spiska->data = new char[15];	//	�������� ����� ��� ���� ������ ��� �������� ������
	cout << "\n\������� ������  ";
	cin >> elem_spiska->data;

	//	���� ���������
	elem_spiska->next = NULL;

	return elem_spiska;
}


//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
void main()
{
	setlocale(LC_ALL,"Russian");
	
	
	//	������	===========================
	list *obj;
	obj = new list;
	
	node *elem_1;
	elem_1 = creating_node();

	node *elem_2;
	elem_2 = creating_node();

	node *elem_3, *elem_4;
	elem_3 = creating_node();
	


//	===========================================================================
//	=============================   TEST   ====================================
//	===========================================================================


	obj->add_node_end(elem_1);
	obj->add_node_end(elem_2);
	obj->add_node_end(elem_3);

	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();


	cout << "\n\n--------------------------------------\n\n";

	cout << "\n\n���������� �������� � �������� �������\n";
	elem_4 = creating_node();
	cout << "\n\n������� �������   ";
	int pos;
	cin >> pos;
	obj->add_node_position(elem_4, pos);

	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();


	cout << "\n\n--------------------------------------\n\n";

	cout << "\n\n�������� �������� �� �������� �������\n";
	cout << "\n\n������� �������   ";
	cin >> pos;
	obj->dell_node_pos(pos);


	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();


	cout << "\n\n--------------------------------------\n\n";

	cout << "\n\n����� �������� �� �������\n";
	cout << "\n\n������� �������   ";
	cin >> pos;
	obj->print_position(pos);

	
	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();



	cout << "\n\n\n";
	system("pause");
}