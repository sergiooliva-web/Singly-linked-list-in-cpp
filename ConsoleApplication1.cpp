
#include <iostream>

class Node {
public:
	double date;
	Node* next;
public:
	Node(double date) {
		this->date = date;
		this->next = NULL;
	}
};

class OneLinkedList {
public:
	Node* head, * tail;
public:
	OneLinkedList() {
		this->head = this->tail = NULL;
	}
	~OneLinkedList() {
		while (head != NULL) pop_front();
	}
	/*--Метод для удаление элементов--*/
	void pop_front() {
		if (head == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		head = node->next;
		delete node;
	}
	/*--Метод для добавление элемента в конец--*/
	void push_back(double date) {
		Node* node = new Node(date);
		if (head == NULL) head = node;
		if (tail != NULL) tail->next = node;
		tail = node;
	}
	/*--Метод для добавление элемента в начало--*/
	void push_front(double date) {
		Node* node = new Node(date);
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;
	}
	/*--Метод для удаление последнего элемента --*/
	void pop_back() {
		if (tail == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}
		Node* node = head;
		for (; node->next != tail; node = node->next);
		node->next = NULL;
		delete tail;
		tail = node;
		
	}
	/*--Метод для возвращения односязанного списка по индексу k --*/
	Node* getAt(int k) {
		if (k < 0) return NULL;
		Node* node = head;
		int n = 0;
		while (node && n != k && node->next) {
			node = node->next;
			n++;
		}
		return (n == k) ? node : NULL;
	}
	/*--Метод для вставки односязанного списка по индексу k --*/
	void insert(int k, double date) {
		Node* left = getAt(k);
		if (left == NULL) return;

		Node* right = left->next;
		Node* node = new Node(date);

		left->next = node;
		node->next = right;
		if (right == NULL) tail = node;
	}
	/*--Метод для удаление промежуточного элемента односязанного списка по индексу k --*/
	void earse(int k) {
		if (k < 0) return;
		if (k == 0) {
			pop_front();
			return;
		}

		Node* left = getAt(k - 1);
		Node* node = left->next;
		if (node == NULL) return;
		Node* right = node->next;

		left->next = right;
		if (node == tail) tail = left;
		delete node;

	}
};


int main()
{	
	OneLinkedList lst;
	lst.push_front(1);
	lst.push_back(2);

	Node* n = lst.getAt(0);
	double d = (n != NULL) ? n->date : 0;
	std::cout << d << std::endl;

	lst.earse(1);
	lst.insert(0, 5);
	lst.insert(0, 2);

	for(Node* node = lst.head; node != NULL; node = node->next)
		std::cout << node -> date << " ";
	
	std::cout << std::endl;
	return 0;
}

