//  File:   SmartPointerList.cpp
//  Author: Rick Halterman


#include <iostream>
#include <memory>

using namespace std;


//  Implements individual nodes within a 
//  singly-linked list
template <typename T>
struct ListNode {
	//  The value of interest in a list element
	T data;
	//  A link to the next element in the list; 
	//  null, if this node is the last element
	shared_ptr<ListNode<T>> next;

	//  Constructor assumes type T is copyable
	ListNode<T>(const T& elem) : data(elem), next(nullptr) {
		cout << "Creating node " << data << endl;
	}

	//  Constructor assumes type T is copyable
	ListNode<T>(const T& elem, shared_ptr<ListNode<T>> n) :
		data(elem), next(n) {
		cout << "Creating node " << data << endl;
	}

	//  Destroys a list node
	virtual ~ListNode<T>() {
		cout << "Destroying node " << data << endl;
	}
};

//  Make a template alias
template <typename T>
using ListNodePtr = shared_ptr<ListNode<T>>;


//  Implements singly-linked list objects.
template <typename T>
class LinkedList {
	//  Points to the first element of this list; null if the list is empty
	ListNodePtr<T> head;
	//  Points to the last element of this list; null if the list is empty
	ListNodePtr<T> tail;
public:
	//  Creates a new, empty list object
	LinkedList<T>() : head(nullptr), tail(nullptr) {
		cout << "Creating a linked list object" << endl;
	}

	//  Destroys this list object
	virtual ~LinkedList<T>() {
		cout << "Destroying an entire linked list object" << endl;
	}

	//  Inserts new element elem onto the back of this list object
	void insert(const T& elem) {
		auto new_node = make_shared<ListNode<T>>(elem);
		if (!head) //  List is empty
			head = tail = new_node;
		else {   //  Add new element to end of list and adjust tail
			tail->next = new_node;
			tail = new_node;
		}
	}

	//  Examines the smart point reference counts for each node
	//  if the list
	void see_refs() const {
		cout << "Head use count: " << head.use_count() << endl;
		cout << "Tail use count: " << tail.use_count() << endl;

		for (auto cursor = head; cursor; cursor = cursor->next) {
			cout << cursor.use_count();
			if (cursor->next)
				cout << '[' << cursor->next.use_count() << ']';
			else
				cout << "[-]";
			cout << "  ";
		}
		cout << endl;
	}


	//  Allows clients to display the contents of a list object
	//  from head to tail
	void print(ostream& os) const {
		os << '{';
		if (head) {
			//  Send first element to stream
			os << head->data;
			//  Send the remaining elements to the stream
			for (auto cursor = head->next; cursor; cursor = cursor->next)
				os << ',' << cursor->data;
		}
		os << '}' << endl;
	}


	////  Allows clients to display the contents of a list object using
	////  using an output stream object like cout
	//template <typename T>
	//friend ostream& operator<<(ostream& os, const LinkedList<T>& list) 
	//{
	//	os << '{';
	//	if ( list.head ) 
	//	{
	//		//  Send first element to stream
	//		os << list.head->data;
	//		//  Send the remaining elements to the stream
	//		for ( auto cursor = list.head->next; cursor; cursor = cursor->next )
	//			os << ',' << cursor->data;
	//	}
	//	os << '}';
	//	return os;
	//}
};

//  Implements individual nodes within a 
//  doubly-linked list
template <typename T>
struct DoubleListNode {
	T data;   //  The value of interest in a list element
	weak_ptr<DoubleListNode<T>> prev;  // Link to the preceding node
	shared_ptr<DoubleListNode<T>> next;

	//  Constructor assumes type T is copyable
	DoubleListNode<T>(const T& elem) : data(elem), next(nullptr) {
		cout << "Creating doubly-linked list node " << data << endl;
	}

	//  Constructor assumes type T is copyable
	DoubleListNode<T>(const T& elem, shared_ptr<DoubleListNode<T>> p,
		shared_ptr<DoubleListNode<T>> n) :
		data(elem), prev(p), next(n) {
		cout << "Creating doubly-linked list node " << data << endl;
	}

	virtual ~DoubleListNode<T>() {
		cout << "Destroying doubly-linked list node " << data << endl;
	}
};

//  Make a template alias
template <typename T>
using DoubleListPtr = shared_ptr<DoubleListNode<T>>;


template <typename T>
class DoubleLinkedList {
	DoubleListPtr<T> head;
	DoubleListPtr<T> tail;
public:
	DoubleLinkedList<T>() : head(nullptr), tail(nullptr) {
		cout << "Creating a doubly-linked list object" << endl;
	}

	virtual ~DoubleLinkedList<T>() {
		cout << "Destroying an entire doubly-linked list object" << endl;
	}


	DoubleListPtr<T> insert(DoubleListPtr<T> p, const T& elem) {
		if (p)
			p->next = insert(p->next, elem);
		else {
			p = make_shared<DoubleListNode<T>>(elem, tail, nullptr);
			tail->next = p;
			tail = p;
		}
		return p;
	}


	void insert(const T& elem) {
		if (!head) //  List is empty
			head = tail = make_shared<DoubleListNode<T>>(elem);
		else
			head->next = insert(head->next, elem);
	}

	void see_refs() const {
		cout << "Head use count: " << head.use_count() << endl;
		cout << "Tail use count: " << tail.use_count() << endl;
		for (auto cursor = head; cursor; cursor = cursor->next) {
			auto p = cursor->prev.lock();
			if (p)
				cout << '[' << p.use_count() << ']';
			else
				cout << "[-]";
			cout << cursor.use_count();
			if (cursor->next)
				cout << '[' << cursor->next.use_count() << ']';
			else
				cout << "[-]";
			cout << "  ";
		}
		cout << endl;

	}

	//  Allows clients to display the contents of a list object
	//  from head to tail
	void print(ostream& os) const {
		os << '{';
		if (head) {
			//  Send first element to stream
			os << head->data;
			//  Send the remaining elements to the stream
			for (auto cursor = head->next; cursor; cursor = cursor->next)
				os << ',' << cursor->data;
		}
		os << '}' << endl;
	}

	//  Allows clients to display the contents of a list object
	//  from tail to head
	void print_reverse(ostream& os) const {
		if (tail) {
			//  Send last element to stream
			os << tail->data;
			//  Send the remaining elements to the stream
			for (auto cursor = tail->prev.lock(); cursor; cursor = cursor->prev.lock())
				os << " <= " << cursor->data;
		}
		os << endl;
	}

	////  Allows clients to display the contents of a list object using
	////  using an output stream object like cout
	//template <typename T>
	//friend ostream& operator<<(ostream& os, const DoubleLinkedList<T>& list) 
	//{
	//	os << '{';
	//	if ( list.head != list.tail) 
	//	{
	//		os << list.head->data;
	//		for ( auto cursor = list.head->next; cursor; cursor = cursor->next )
	//			os << ',' << cursor->data;
	//	}
	//	os << '}';
	//	return os;
	//}
};


void make_list() {
	cout << "Beginning make list" << endl;
	LinkedList<int> int_list;

	int_list.insert(4);
	int_list.insert(-34);
	int_list.insert(55);
	int_list.insert(12);
	int_list.insert(0);
	int_list.insert(-11);
	//cout << int_list << endl;
	int_list.print(cout);
	int_list.see_refs();
	cout << "Ending make list" << endl;
}

void make_double_list() {
	cout << "Beginning make double list" << endl;
	DoubleLinkedList<int> int_list;

	int_list.insert(4);
	int_list.insert(-34);
	int_list.insert(55);
	int_list.insert(12);
	int_list.insert(0);
	int_list.insert(-11);
	//cout << int_list << endl;
	int_list.print(cout);
	int_list.print_reverse(cout);
	int_list.see_refs();
	cout << "Ending make double list" << endl;
}

int main() {
	cout << "Beginning main" << endl;
	cout << "\n---------------------\n" << endl;
	make_list();
	cout << "\n---------------------\n" << endl;
	make_double_list();
	cout << "\n---------------------\n" << endl;
	cout << "Ending main" << endl;
}

