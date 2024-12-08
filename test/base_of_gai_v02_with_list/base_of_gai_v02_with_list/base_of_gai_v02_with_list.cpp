#include <iostream>
using namespace std;

struct list_node;
class list;
class base;

//	Элемент дерева
struct node				//	--------------------- LIST ------------------------
{
	int number;
	list *data_list;
	char narushenie[10];

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
	};							//		Конструктор и деструктор
	~base()						//------------------------------
	{							//------------------------------
								//------------------------------
	}							//------------------------------
//--------------------------------------------------------------
;

	//	----------------------------------------------------------------------------- OK --------------------------	
;	
	//	Нахождение позиции элемента по её номеру. Поиск в ветке с pointer
	//	- возвращает указатель на ноду при нахождении
	//	- возвращает NULL при ртсутствии совпадений
	node* find_node(int NUMBER, node *pointer)
	{
		//	Проверка, поиск во всём дереве?
			if(pointer == NULL)
			//	Да, искать во всём дереве
			{
				pointer = root;
			}

		
		if (NUMBER < pointer->number )	
		//	По левой ветке
			{
				if (pointer->left==NULL)
				{
					cout << "\n\nСовпадений не найдено";
					return NULL;		//	Совпадений не найдено, слева ветка отсутствует
				}

				//	Левая ветка есть
				pointer = pointer->left;			//	Передвигаем указатель далее влево
				find_node(NUMBER, pointer);			//	Повторяем проверку для текущей ноды
			}
		
		//	По правой ветке
		else
			{
				if (pointer->number == NUMBER)	//	Проверка на совпадение
				{
					return pointer;				//	Возвращаем указатель на родитель к новому элементу
				}

				if (pointer->right==NULL)
				{
					cout << "\n\nСовпадений не найдено";
					return NULL;				//	Совпадений не найдено, справа ветка отсутствует. Возвращаем указатель на предыдущую ноду
				}
				//	Правая ветка есть
				pointer = pointer->right;		//	Передвигаем указатель далее вправо
				find_node(NUMBER, pointer);		
			}
	}



	//	----------------------------------------------------------------------------- OK --------------------------	
;
	//	Нахождение позиции элемента по её номеру. Поиск от корня дерева
	//	- возвращает указатель на ноду при нахождении
	//	- возвращает NULL при ртсутствии совпадений
	node* find_node(int NUMBER)
	{
		node *pointer;
		pointer = root;
				
		if (NUMBER < pointer->number )	
		//	По левой ветке
			{
				//	Совпадений не найдено, слева ветка отсутствует
					if (pointer->left==NULL)
					{
						cout << "\n\nСовпадений не найдено";
						return NULL;						
					}

				//	Левая ветка есть
					pointer = pointer->left;				//	Передвигаем указатель далее влево
					find_node(NUMBER, pointer);				//	Повторяем проверку для текущей ноды
			}
		
		//	По правой ветке
			else
			{
				//	Проверка на совпадение
					if (pointer->number == NUMBER)	
					{
						return pointer;				//	Возвращаем указатель на родитель к новому элементу
					}

				//	Проверка отсутствия ветки справа. 
					if (pointer->right==NULL)
					{
						cout << "\n\nСовпадений не найдено.";
						return NULL;
					}

				//	Правая ветка есть
					pointer = pointer->right;		//	Передвигаем указатель далее вправо
					find_node(NUMBER, pointer);
			}
	}



	//	Нахождение позиции родителя элемента по её номеру. Поиск по ветке
	//	- возвращает указатель на ноду при нахождении
	//	- возвращает NULL при ртсутствии совпадений
	node* find_node_parent(int NUMBER, node *pointer)
	{
		//	Проверка, поиск во всём дереве?
			if(pointer == NULL)
			//	Да, искать во всём дереве
			{
				pointer = root;
			}

		
		if (NUMBER < pointer->number )	
		//	По левой ветке
			{
				if (pointer->left==NULL)
				{
					return pointer;		//	Совпадений не найдено, слева ветка отсутствует
				}

				//	Левая ветка есть
				pointer = pointer->left;			//	Передвигаем указатель далее влево
				find_node_parent(NUMBER, pointer);			//	Повторяем проверку для текущей ноды
			}
		
		//	По правой ветке
		else
			{
				if (pointer->number == NUMBER)	//	Проверка на совпадение
				{
					return pointer;				//	Возвращаем указатель на родитель к новому элементу
				}

				if (pointer->right==NULL)
				{
					return pointer;				//	Совпадений не найдено, справа ветка отсутствует. Возвращаем указатель на предыдущую ноду
				}
				//	Правая ветка есть
				pointer = pointer->right;		//	Передвигаем указатель далее вправо
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


	//	Метод нахождения элемента с максимальным значением номера для данной ветки
	//	- Null - если проверяемый узел не существует
	node* find_max_node(node *pointer)
	{
		//	Проверка существования ветки
		if(pointer == NULL)
		//	Ветка не существует
		{
			cout << "\n\nVetka dlia poiska ne suschestvuet";
			return NULL;
		}

		//	Ветка существует
		//	Перебор элементов правой ветки от узла корня
		while(pointer->right != NULL)
		{
			pointer = pointer->right;
		}
		return pointer;
	}



	

	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;	
	//	Добавляем поле правонарушения в уже созданный элемент	--------------------- LIST ------------------------
	node* create_node(node *element)
	{
		//cout << "\nВведите нарушение  ";
		//cin >> element->narushenie;
		
		//	Создаём новый указатель для доступа к обьекту класс элемента дерева
			list *tmp_list;
			tmp_list = element->data_list;
		
		tmp_list->add_node_end(tmp_list->creating_node());
		
		//element->data_list->->add_node_end();

		return element;
	}
	

	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Проверка: База пуста ?   true - Пуста, false - НЕ пуста
	bool baza_pusta(node *test)	
	{
		if (test==0)			//		база пуста?
		return true;			//			 пуста
		return false;			//			 не пуста
	}
	


	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Добавление элемента в дерево, или создание нового при использовании параметра по умолчанию
	node* add_elem(node *adding_node = NULL)
	{
		//	Проверка, создаём новый элемент?
		if(adding_node == NULL)
		//	Да, создаём новый элемент
		{
			adding_node = create_node();
		}

		//	Нет, передаём уже созданный элемент

		//	База пуста?
			if (baza_pusta(root))			
			//	Да, База пуста
			{
				root = adding_node;		//	Переуказываем указатель на корень дерева

				//	Обнуляем поля в новом элементе
					adding_node->prev = NULL;	
					adding_node->left = NULL;	
					adding_node->right = NULL;	
					return adding_node;			
			}

		//	База изначально НЕ пуста:
		node *temp;
		temp = find_node_parent(adding_node->number, root);	//	Новый указатель указывает либо на совпадающий по номеру элемент, либо на предок добавляемого при отсутствии совпадения

		//	элемент совпадает с существующим?
  		if(temp->number == adding_node->number)
		// Да, совпадает
		{
			cout << "\n\nElement suschestvuet. Dobavte pravonarushenie  \n";
			create_node(temp);								//	Добавляем правонарушение в уже существующий элемент
			return temp;
		}

		// Нет, не существует
		//	Проверка места добавления элемента
		if(adding_node->number < temp->number)
		
		//	Добавляем слева
		{
			temp->left = adding_node;
		}

		//	Добавляем справа
		else
		{
			temp->right = adding_node;
		}

		adding_node->prev = temp;
		return adding_node;
	}


	
	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Создаём новый элемент без добавление в дерево
	node* create_node()
	{
		node *element = new node;		

//		list *bufer_data_list = new list;
		cout << "\n\nВведите номер карточки  ";
		cin >> element->number;
		
		//cout << "\nВведите нарушение  ";
		//cin >> element->narushenie;

		//	Создаем первый элемент списка
			element->data_list = new list;
			
			//	Создаём новый указатель для возможности доступа к обьекту класс элемента дерева
				list *tmp_list;
				tmp_list = element->data_list;

			//	Добавляем первый элемент в список
				tmp_list->add_node_end(tmp_list->creating_node());

		//	Создание элемента списка и добавление его в список	
			//bufer_data_list->add_node_end(creating_node());
			//list_node *tmp_elem_list;
			//tmp_elem_list = creating_node();
			//list_obj->add_node_end(tmp_elem_list);

			//element->data_list = list_obj;

		element->prev = NULL;
		element->left = NULL;
		element->right = NULL;

		return element;
	}


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Нахождение следующей ноды
	//	- NULL - если следующей ноды не существует
	node* find_next_node(node *testing_node)
	{
		//	Проверка отсутствия правого потомка
		if (testing_node->right == 0)
		
		//	Правый потомок отсутствует	-------------------
			{
				//	Проверка наличия родителя
				if(testing_node->prev == NULL)
			
				//	Родитель отсутствует
				{
					return NULL;
				}

				//	Родитель присутствует
					//	Элемент меньше родителя. В таком случае следующий элемент будет родитель
						if (testing_node->number < testing_node->prev->number)
						{
							testing_node = testing_node->prev;
							return testing_node;
						}
					//	Проверка существования родителя у родителя. В этом случае он будет следующим элементов
						if(testing_node->prev->prev != NULL)
							testing_node = testing_node->prev->prev;
						else
							return NULL;			//	Случай когда предок не имеет предка. В таком случае следующего элемента нет
						return testing_node;
			}

		//	Правый потомок существует	-------------------
			testing_node = testing_node->right;
			testing_node = find_min_node(testing_node);
			return testing_node;
	}



	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Нахождение предыдущего существующего элемента по номеру меньшего указанного
	node* find_prev_node(int number)
	{
		//	Проверка база пуста?
			if (root == NULL)
			{
				cout << "\n\nБаза пуста";
				return false;
			}


		node *testing_node, *next_tested;
		testing_node = root;

			//	Переходим на самый минимальный элемент
				testing_node = find_min_node(root);

				//Находим следующий элемент пока значение следующего не будет больше 
				//номера или пока будут элемены в дереве
					while(testing_node->number <= number)
					{
							//	Проверка существования следующего элемента. И проверка чтоб его значение небыло больше поиска
								next_tested = find_next_node(testing_node);
								if( (next_tested == NULL) || (next_tested->number >= number) ) return testing_node;
							testing_node = next_tested;	//	Подтягиваем указатель на проверенный элемент который существует и меньше искомого
					}
	}





	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Печть элемента дерева
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
	//	Печать карточки по номеру
	bool print_kartochka_number(int number)
	{
		node *tmp;
		tmp = find_node(number);
		print_node(tmp);
		return true;
	}

	

	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Печать всего дерева
	//	- FALSE - если дерево пусто, или элемент отсутствует
	bool print_all_node()
	{
		//	Проверка на существование элементов в методе print_region
		//	элемент существует
		node *min_elem, *max_elem;
		min_elem = find_min_node(root);			//	самый минимальный элемент
		max_elem = find_max_node(root);			//	самый максимальный элемент
		
		//	Выводим на экран элементы диапазона
		print_region(min_elem->number, max_elem->number);
		return true;
	}




	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
;
	//	Печать всей ветви от элемента. Если без параметров - печпть всего дерева
	//	- FALSE - если дерево пусто, или элемент отсутствует
	bool print_all_node(node *printing_point)
	{
		//	Проверка на существование элементов в методе print_region
		//	элемент существует
		node *min_elem, *max_elem;//*koren, 
		//koren = printing_point;								//	Указатель на корневой элемент ветки
		min_elem = find_min_node(printing_point);			//	самый минимальный элемент
		max_elem = find_max_node(printing_point);			//	самый максимальный элемент
		
		//	Выводим на экран элементы диапазона
		print_region(min_elem->number, max_elem->number);
		return true;
	}
		


	//	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK	OK
	;
	//	Вывод элементов диапазона включительно
	void print_region(int start, int end)	
	{
		//	Меняем местами если END > START
			if(start > end)
			{
				int tmp;
				tmp = start;
				start = end;
				end = tmp;
			}

		//	Проверка выхода за пределы всех элементов
			node *min_elem, *max_elem;

			min_elem = find_min_node(get_root());
			max_elem = find_max_node(get_root());
			
			//	Корректировка номеров
				node *start_node, *end_node;
				//	Проверка если во всём диапазоне нет єлементов дерева для вывода
					if( (start > max_elem->number) || (end < min_elem->number) )
					{
						cout << "\n\nНет элементов для вывода с текущего диапазона";
						return;
					}
				if(start < min_elem->number) start = min_elem->number;
				if(end > max_elem->number) end = max_elem->number;

			start_node = find_node_parent(start, NULL);
			end_node = find_node_parent(end, NULL);

			//	Устранение присваивания следующего элемента справа
				if (end_node->number > end) end_node = find_prev_node(end_node->number);//--------------------------- присвоить предыдущий реально существующий элемент


		node *printing_point;
		printing_point = start_node;

		print_node(printing_point);
		//	Печатаем до элемента END
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
	//	Метод получения указателя на корень дерева
	node* get_root()
	{
		return root;
	}
};


//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------- LIST ----------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

struct list_node
{
	char *data;
	list_node *next;
};

class list
{
	list_node *head;
	list_node *hvost;
public:
	list_node* creating_node();
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
		list_node *prev = NULL, *next = NULL, *dell_node = NULL;
		
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
					this->head = next;
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
		list_node *ukaz;
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
	list_node* add_node_position(list_node *element, int position)
	{
		list_node *prev = NULL, *next = NULL;
		
		
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
	list_node* find_position(int position)
	{
		list_node *ukaz;
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
		list_node *ukaz;
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
		list_node *tmp;
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
	list_node* add_node_end(list_node *element)
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
list_node* list::creating_node()
{
	//	Создание элемента списка	-------
	list_node *elem_spiska;
	elem_spiska = new list_node;

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
/*
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
*/
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================

void main()
{
	setlocale(LC_ALL, "Russian");

	base *gai;
	gai = new base;


//	==================================================================================================================================================
//	===================================================== TEST =======================================================================================
//	==================================================================================================================================================



	//	Проверка метода добавления элементов в пустую базу и в базу с уже существующими элементами
		node *a, *b, *c, *tmp;
	
		a = gai->add_elem();
/*	tmp = gai->create_node();
		gai->add_elem(tmp);
		b = gai->add_elem();
		c = gai->add_elem();
*/	

	cout << "\n\n ------- Проверка метода вывода на экран всех карточек -------------- ";
	gai->print_all_node();

/*

	cout << "\n\n ------- Проверка метода вывода на экран карточки по номеру -------- ";
	int nomer_kartochki;

	cout << "\nВведите номер карточки для поиска   ";
	cin >> nomer_kartochki;
	
	gai->print_kartochka_number(nomer_kartochki);

	

	cout << "\n\n ------- Вывод на экран карточек c выбранного диапазона номеров ------- ";
	int start_region_number = 0, end_region_number = 0;
	cout << "\n\nВведите начального номера карточки для поиска  ";
	cin >> start_region_number;
	cout << "\nВведите оконечного номера карточки для поиска  ";
	cin >> end_region_number;

	gai->print_region(start_region_number, end_region_number);

*/


	cout << "\n\n\n";
	system("pause");
}