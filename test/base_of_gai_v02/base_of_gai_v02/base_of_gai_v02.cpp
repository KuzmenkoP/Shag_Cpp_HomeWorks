#include <iostream>
using namespace std;

struct node				//	--------------------- LIST ------------------------
{
	int number;
	char narushenie[10];
public:
	node *prev;
	node *left;
	node *right;
};


class base
{
private:
	node *root; 
public:
//--------------------------------------------------------------
	base()						//------------------------------
	{							//------------------------------
		root = NULL;			//------------------------------
	};							//		����������� � ����������
	~base()						//------------------------------
	{							//------------------------------
								//------------------------------
	}							//------------------------------
//--------------------------------------------------------------
;

	//	----------------------------------------------------------------------------- OK --------------------------	
;	
	//	���������� ������� �������� �� � ������. ����� � ����� � pointer
	//	- ���������� ��������� �� ���� ��� ����������
	//	- ���������� NULL ��� ���������� ����������
	node* find_node(int NUMBER, node *pointer)
	{
		//	��������, ����� �� ��� ������?
			if(pointer == NULL)
			//	��, ������ �� ��� ������
			{
				pointer = root;
			}

		
		if (NUMBER < pointer->number )	
		//	�� ����� �����
			{
				if (pointer->left==NULL)
				{
					cout << "\n\n���������� �� �������";
					return NULL;		//	���������� �� �������, ����� ����� �����������
				}

				//	����� ����� ����
				pointer = pointer->left;			//	����������� ��������� ����� �����
				find_node(NUMBER, pointer);			//	��������� �������� ��� ������� ����
			}
		
		//	�� ������ �����
		else
			{
				if (pointer->number == NUMBER)	//	�������� �� ����������
				{
					return pointer;				//	���������� ��������� �� �������� � ������ ��������
				}

				if (pointer->right==NULL)
				{
					cout << "\n\n���������� �� �������";
					return NULL;				//	���������� �� �������, ������ ����� �����������. ���������� ��������� �� ���������� ����
				}
				//	������ ����� ����
				pointer = pointer->right;		//	����������� ��������� ����� ������
				find_node(NUMBER, pointer);		
			}
	}



	//	----------------------------------------------------------------------------- OK --------------------------	
;
	//	���������� ������� �������� �� � ������. ����� �� ����� ������
	//	- ���������� ��������� �� ���� ��� ����������
	//	- ���������� NULL ��� ���������� ����������
	node* find_node(int NUMBER)
	{
		node *pointer;
		pointer = root;
				
		if (NUMBER < pointer->number )	
		//	�� ����� �����
			{
				//	���������� �� �������, ����� ����� �����������
					if (pointer->left==NULL)
					{
						cout << "\n\n���������� �� �������";
						return NULL;						
					}

				//	����� ����� ����
					pointer = pointer->left;				//	����������� ��������� ����� �����
					find_node(NUMBER, pointer);				//	��������� �������� ��� ������� ����
			}
		
		//	�� ������ �����
			else
			{
				//	�������� �� ����������
					if (pointer->number == NUMBER)	
					{
						return pointer;				//	���������� ��������� �� �������� � ������ ��������
					}

				//	�������� ���������� ����� ������. 
					if (pointer->right==NULL)
					{
						cout << "\n\n���������� �� �������.";
						return NULL;
					}

				//	������ ����� ����
					pointer = pointer->right;		//	����������� ��������� ����� ������
					find_node(NUMBER, pointer);
			}
	}



	//	���������� ������� �������� �������� �� � ������. ����� �� �����
	//	- ���������� ��������� �� ���� ��� ����������
	//	- ���������� NULL ��� ���������� ����������
	node* find_node_parent(int NUMBER, node *pointer)
	{
		//	��������, ����� �� ��� ������?
			if(pointer == NULL)
			//	��, ������ �� ��� ������
			{
				pointer = root;
			}

		
		if (NUMBER < pointer->number )	
		//	�� ����� �����
			{
				if (pointer->left==NULL)
				{
					return pointer;		//	���������� �� �������, ����� ����� �����������
				}

				//	����� ����� ����
				pointer = pointer->left;			//	����������� ��������� ����� �����
				find_node_parent(NUMBER, pointer);			//	��������� �������� ��� ������� ����
			}
		
		//	�� ������ �����
		else
			{
				if (pointer->number == NUMBER)	//	�������� �� ����������
				{
					return pointer;				//	���������� ��������� �� �������� � ������ ��������
				}

				if (pointer->right==NULL)
				{
					return pointer;				//	���������� �� �������, ������ ����� �����������. ���������� ��������� �� ���������� ����
				}
				//	������ ����� ����
				pointer = pointer->right;		//	����������� ��������� ����� ������
				find_node_parent(NUMBER, pointer);		
			}
	}
	

	node* find_min_node(node *pointer)
	{
		while (pointer->left != 0)
		{
			pointer = pointer->left;
		}
		return pointer;
	}


	//	����� ���������� �������� � ������������ ��������� ������ ��� ������ �����
	//	- Null - ���� ����������� ���� �� ����������
	node* find_max_node(node *pointer)
	{
		//	�������� ������������� �����
		if(pointer == NULL)
		//	����� �� ����������
		{
			cout << "\n\nVetka dlia poiska ne suschestvuet";
			return NULL;
		}

		//	����� ����������
		//	������� ��������� ������ ����� �� ���� �����
		while(pointer->right != NULL)
		{
			pointer = pointer->right;
		}
		return pointer;
	}



	

	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;	
	//	��������� ���� �������������� � ��� ��������� �������	--------------------- LIST ------------------------
	node* create_node(node *element)
	{
		cout << "\n������� ���������  ";
		cin >> element->narushenie;

		return element;
	}
	

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	��������: ���� ����� ?   true - �����, false - �� �����
	bool baza_pusta(node *test)	
	{
		if (test==0)			//		���� �����?
		return true;			//			 �����
		return false;			//			 �� �����
	}
	


	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	���������� �������� � ������, ��� �������� ������ ��� ������������� ��������� �� ���������
	node* add_elem(node *adding_node = NULL)
	{
		//	��������, ������ ����� �������?
		if(adding_node == NULL)
		//	��, ������ ����� �������
		{
			adding_node = create_node();
		}

		//	���, ������� ��� ��������� �������

		//	���� �����?
			if (baza_pusta(root))			
			//	��, ���� �����
			{
				root = adding_node;		//	������������� ��������� �� ������ ������

				//	�������� ���� � ����� ��������
					adding_node->prev = NULL;	
					adding_node->left = NULL;	
					adding_node->right = NULL;	
					return adding_node;			
			}

		//	���� ���������� �� �����:
		node *temp;
		temp = find_node_parent(adding_node->number, root);	//	����� ��������� ��������� ���� �� ����������� �� ������ �������, ���� �� ������ ������������ ��� ���������� ����������

		//	������� ��������� � ������������?
  		if(temp->number == adding_node->number)
		// ��, ���������
		{
			cout << "\n\nElement suschestvuet. Dobavte pravonarushenie  \n";
			create_node(temp);								//	��������� �������������� � ��� ������������ �������
			return temp;
		}

		// ���, �� ����������
		//	�������� ����� ���������� ��������
		if(adding_node->number < temp->number)
		
		//	��������� �����
		{
			temp->left = adding_node;
		}

		//	��������� ������
		else
		{
			temp->right = adding_node;
		}

		adding_node->prev = temp;
		return adding_node;
	}


	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	������ ����� ������� ��� ���������� � ������
	node* create_node()
	{
		node *element = new node;
		cout << "\n\n������� ����� ��������  ";
		cin >> element->number;
		
		cout << "\n������� ���������  ";
		cin >> element->narushenie;

		element->prev = NULL;
		element->left = NULL;
		element->right = NULL;

		return element;
	}


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	���������� ��������� ����
	//	- NULL - ���� ��������� ���� �� ����������
	node* find_next_node(node *testing_node)
	{
		//	�������� ���������� ������� �������
		if (testing_node->right == 0)
		
		//	������ ������� �����������	-------------------
			{
				//	�������� ������� ��������
				if(testing_node->prev == NULL)
			
				//	�������� �����������
				{
					return NULL;
				}

				//	�������� ������������
					//	������� ������ ��������. � ����� ������ ��������� ������� ����� ��������
						if (testing_node->number < testing_node->prev->number)
						{
							testing_node = testing_node->prev;
							return testing_node;
						}
					//	�������� ������������� �������� � ��������. � ���� ������ �� ����� ��������� ���������
						if(testing_node->prev->prev != NULL)
							testing_node = testing_node->prev->prev;
						else
							return NULL;			//	������ ����� ������ �� ����� ������. � ����� ������ ���������� �������� ���
						return testing_node;
			}

		//	������ ������� ����������	-------------------
			testing_node = testing_node->right;
			testing_node = find_min_node(testing_node);
			return testing_node;
	}



	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	���������� ����������� ������������� �������� �� ������ �������� ����������
	node* find_prev_node(int number)
	{
		//	�������� ���� �����?
			if (root == NULL)
			{
				cout << "\n\n���� �����";
				return false;
			}


		node *testing_node, *next_tested;
		testing_node = root;

			//	��������� �� ����� ����������� �������
				testing_node = find_min_node(root);

				//������� ��������� ������� ���� �������� ���������� �� ����� ������ 
				//������ ��� ���� ����� ������� � ������
					while(testing_node->number <= number)
					{
							//	�������� ������������� ���������� ��������. � �������� ���� ��� �������� ������ ������ ������
								next_tested = find_next_node(testing_node);
								if( (next_tested == NULL) || (next_tested->number >= number) ) return testing_node;
							testing_node = next_tested;	//	����������� ��������� �� ����������� ������� ������� ���������� � ������ ��������
					}
	}





	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	����� �������� ������
	bool print_node(node *printing_node = NULL)
	{
		if(printing_node != NULL)
		{
			cout << "\n\n\tNomer = " << printing_node->number << "\t--- Narushenie " << printing_node->narushenie;
		return true;
		}

		return false;
/*			if(root == NULL) return false;
			cout << "\n\n\tNomer = " << root->number << "\t--- Narushenie " << root->narushenie;
			return true;
*/
	}


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	������ �������� �� ������
	bool print_kartochka_number(int number)
	{
		node *tmp;
		tmp = find_node(number);
		print_node(tmp);
		return true;
	}

	

	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	������ ����� ������
	//	- FALSE - ���� ������ �����, ��� ������� �����������
	bool print_all_node()
	{
		//	�������� �� ������������� ��������� � ������ print_region
		//	������� ����������
		node *min_elem, *max_elem;
		min_elem = find_min_node(root);			//	����� ����������� �������
		max_elem = find_max_node(root);			//	����� ������������ �������
		
		//	������� �� ����� �������� ���������
		print_region(min_elem->number, max_elem->number);
		return true;
	}




	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	������ ���� ����� �� ��������. ���� ��� ���������� - ������ ����� ������
	//	- FALSE - ���� ������ �����, ��� ������� �����������
	bool print_all_node(node *printing_point)
	{
		//	�������� �� ������������� ��������� � ������ print_region
		//	������� ����������
		node *min_elem, *max_elem;//*koren, 
		//koren = printing_point;								//	��������� �� �������� ������� �����
		min_elem = find_min_node(printing_point);			//	����� ����������� �������
		max_elem = find_max_node(printing_point);			//	����� ������������ �������
		
		//	������� �� ����� �������� ���������
		print_region(min_elem->number, max_elem->number);
		return true;
	}
		


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	;
	//	����� ��������� ��������� ������������
	void print_region(int start, int end)	
	{
		//	������ ������� ���� END > START
			if(start > end)
			{
				int tmp;
				tmp = start;
				start = end;
				end = tmp;
			}

		//	�������� ������ �� ������� ���� ���������
			node *min_elem, *max_elem;

			min_elem = find_min_node(get_root());
			max_elem = find_max_node(get_root());
			
			//	������������� �������
				node *start_node, *end_node;
				//	�������� ���� �� ��� ��������� ��� ��������� ������ ��� ������
					if( (start > max_elem->number) || (end < min_elem->number) )
					{
						cout << "\n\n��� ��������� ��� ������ � �������� ���������";
						return;
					}
				if(start < min_elem->number) start = min_elem->number;
				if(end > max_elem->number) end = max_elem->number;

			start_node = find_node_parent(start, NULL);
			end_node = find_node_parent(end, NULL);

			//	���������� ������������ ���������� �������� ������
				if (end_node->number > end) end_node = find_prev_node(end_node->number);//--------------------------- ��������� ���������� ������� ������������ �������


		node *printing_point;
		printing_point = start_node;

		print_node(printing_point);
		//	�������� �� �������� END
			while( (printing_point->number < end_node->number) ) //&& (printing_point->right != NULL) && (printing_point->prev != NULL) 
			{
//				if (printing_point->right != NULL) printing_point = printing_point->right;
//				if( (printing_point->right == NULL) && (printing_point->prev != NULL) ) printing_point = printing_point->prev;
				printing_point = find_next_node(printing_point);
			//	if (printing_point == NULL) return;
				print_node(printing_point);
			}
	}
	


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	����� ��������� ��������� �� ������ ������
	node* get_root()
	{
		return root;
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");

	base *gai;
	gai = new base;


//	==================================================================================================================================================
//	===================================================== TEST =======================================================================================
//	==================================================================================================================================================

	//	�������� ������ ���������� ��������� � ������ ���� � � ���� � ��� ������������� ����������
		node *a, *b, *c, *tmp;
	
		a = gai->add_elem();
	tmp = gai->create_node();
		gai->add_elem(tmp);
		b = gai->add_elem();
		c = gai->add_elem();
	

	cout << "\n\n ------- �������� ������ ������ �� ����� ���� �������� -------------- ";
	gai->print_all_node();



	cout << "\n\n ------- �������� ������ ������ �� ����� �������� �� ������ -------- ";
	int nomer_kartochki;

	cout << "\n������� ����� �������� ��� ������   ";
	cin >> nomer_kartochki;
	
	gai->print_kartochka_number(nomer_kartochki);

	

	cout << "\n\n ------- ����� �� ����� �������� c ���������� ��������� ������� ------- ";
	int start_region_number = 0, end_region_number = 0;
	cout << "\n\n������� ���������� ������ �������� ��� ������  ";
	cin >> start_region_number;
	cout << "\n������� ���������� ������ �������� ��� ������  ";
	cin >> end_region_number;

	gai->print_region(start_region_number, end_region_number);


	cout << "\n\n\n";
	system("pause");
}