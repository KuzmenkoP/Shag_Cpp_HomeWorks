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
	//	Удаление элемента по его позиции
	//	--- 0 - соответствует первому элементу
	void dell_node_pos(int position)
	{
		node *prev = NULL, *next = NULL, *dell_node = NULL;
		
		dell_node = find_position(position);

		//	Проверка на существование элемента с указанным индексом
				//	Элемент с указанным индексом отсутствует?
				if(dell_node == NULL)
				{
					cout << "\n\nЭлемент с указанным индексом отсутствует";
					return;
				}
		
		
		prev = find_position(position - 1);
		next = find_position(position + 1);
		//	prev - Предварителого элемента НЕТ?
				if(prev == NULL)
				//	Да, предварительный элемент не существует
				{
					head = next;
					delete dell_node;
					return;
				}
				else
				{
					prev->next = next;
				}

		//	next - Следующего элемента не существует
				if(next == NULL)
				//	Да, удаляем крайний элемент списка
				{
					prev->next = NULL;
					hvost = prev;
				}
		
		delete dell_node;
	}





	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	Метод возвращает количество элементов в списке
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
	//	Добавление элемента в заданную позицию
	//	---	0 - соответствует первому элементу списка
	node* add_node_position(node *element, int position)
	{
		node *prev = NULL, *next = NULL;
		
		
		//	Корректировка позиции элемента в случае ввода неверной позиции выходящей за пределы
			if(position <= 0)
				{
					position=0;
					next = find_position(position);
					head = element;
					element->next = next;

					return element;
				}

		//	Позиция вставляемого элемента больше позиции крайнего элемента списка
			if(position >= cnt_elem())
			{
				add_node_end(element);
				return element;
			}

		//	Позиция заданна корректно и входит в диапазон
			prev = find_position(position-1);
			next = find_position(position);

			prev->next = element;
			element->next = next;

			return element;
	}

	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	Поиск элемента по заданной позиции
	//	---	0	- соответствует первому элементу списка
	//	--- NULL- возвращается вслучае отсутствия элемента с соответствующим индексом 
	node* find_position(int position)
	{
		node *ukaz;
		ukaz = head;

		//	Проверки на совпадение по диапазону позиции
				//	Если список пуст возвращаем NULL
				if(ukaz == NULL) return NULL;
		
				//	Если позиция элемента больше крайнего элемента списка возвращаем NULL
				if( (position >= cnt_elem()) || (position < 0) ) return NULL;

		//	Всё ОК, позиция указывает на существующий элемент списка
				for (int i = 1; i <= position; i++)
				{
					ukaz = ukaz->next;
				}

		return ukaz;
	}

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	Вывод всего списка
	//	--- 0 - соответствует первому элементу списка
	void print_all()
	{
		//	Список пуст?
		if (head == NULL)
		//	Да, список пуст
		{
			cout << "\n\nСписок пуст";
			return;
		}

		//	Нет, список не пуст
		node *ukaz;
		ukaz = head;

		int i = 0;			//	Номер элемента, используется только для вывода на экран
		cout << "\nЕлемент списка " << i << "  " << ukaz->data;

		

		while(ukaz != hvost)
		{
			ukaz = ukaz->next;
			i++;
			cout << "\nЕлемент списка " << i << "  " << ukaz->data;
		}
		return;
	};

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	Вывод списка по позиции
	//	--- 0 - соответствует первому элементу списка
	void print_position(int position)
	{
		node *tmp;
		tmp = find_position(position);
		if (tmp == NULL)
		{
			cout << "\n\nЭлемент с указанным индексом не существует";
			return;
		}			
			
		cout << "\nЕлемент списка " << position << "  " << tmp->data;
		return;
	}


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	//	Добавление элемента в конец списка
	node* add_node_end(node *element)
	{
		//	Список пуст?
		if (head == NULL)
		//	Да, список пуст
		{
			hvost = element;
			head = element;
		}
		
		//	Нет, список не пуст
		else
		{
		hvost->next = element;	//	Указатель NEXT последнего элемента списка переуказываем на новый элемент
		hvost = element;
		}

		element->next = NULL;	//	Обнуляем поле NEXT нового элемента
		
		return element;
	}
};

//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
//	Функция создания элемента списка для дальнейшей вставки в список
node* creating_node()
{
	//	Создание элемента списка	-------
	node *elem_spiska;
	elem_spiska = new node;

	//	Поле данных		- - - -
	elem_spiska->data = new char[15];	//	Выделяем место под поле данных для элемента списка
	cout << "\n\Введите данные  ";
	cin >> elem_spiska->data;

	//	Поле указателя
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
	
	
	//	Список	===========================
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

	cout << "\n\nДобавление элемента в заданную позицию\n";
	elem_4 = creating_node();
	cout << "\n\nВведите позицию   ";
	int pos;
	cin >> pos;
	obj->add_node_position(elem_4, pos);

	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();


	cout << "\n\n--------------------------------------\n\n";

	cout << "\n\nУдаление элемента по заданной позиции\n";
	cout << "\n\nВведите позицию   ";
	cin >> pos;
	obj->dell_node_pos(pos);


	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();


	cout << "\n\n--------------------------------------\n\n";

	cout << "\n\nПоиск элемента по позиции\n";
	cout << "\n\nВведите позицию   ";
	cin >> pos;
	obj->print_position(pos);

	
	cout << "\n\n--------------------------------------\n\n";

	obj->print_all();



	cout << "\n\n\n";
	system("pause");
}