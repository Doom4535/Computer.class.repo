#ifndef DEFINED_SENTINELLLIST_H_
#define DEFINED_SENTINELLLIST_H_

#include <iostream>

//  Represents an ordered, doubly-linked list.
//  Uses sentinel nodes to simplify the method implementations.
template <typename T>
class List {
protected:
	struct Node {
		T data;           //  The data of interest
		Node *next;       //  Link to successor node
		Node *prev;       //  Link to predecessor node
	};

	Node *head, *tail;    //  Pointers to the sentinel nodes

	int current_size;     //  Number of elements in the list

	//  Copy constructor inaccessible to clients
	List(const List<T>& other);
	//  Assignment inaccessible to clients
	List<T>& operator=(const List<T>& other);
public:
	List() : head(new Node), tail(new Node), current_size(0) {
		head->next = tail;
		tail->prev = head;
	}

	~List() {   //  Free up the space held by the list
		Node *p = head;
		while (p != tail)
		{
			Node *temp = p;
			p = p->next;
			delete temp;
		}
		delete p;
	}

	//  Returns the number of elements in the list
	int size() const {
		return current_size;
	}

	/*
	void insert(const T& elem) {
	Node *new_node = new Node;
	new_node->data = elem;
	new_node->next = tail;
	new_node->prev = tail->prev;
	tail->prev->next = new_node;
	tail->prev = new_node;
	current_size++;   //  Now one more
	}
	*/

	//  Inserts elem into its proper place within
	//  the list
	void insert(const T& elem) {
		//  Find location to insert the element
		Node *p = head->next;
		while (p != tail && p->data < elem)
			p = p->next;
		//  Make the new node
		Node *new_node = new Node;
		new_node->data = elem;
		//  Link in the new node
		new_node->prev = p->prev;
		new_node->next = p;
		p->prev = new_node;
		new_node->prev->next = new_node;

		current_size++;   //  Now one more
	}

	//  Removes elem from the list, if possible.
	//  Returns true if successful; otherwise, returns false.
	bool remove(const T& elem) {
		//  Find element to remove
		bool result = false;  //  Fail by default
		Node *p = head->next;
		while (p != tail && p->data != elem)
			p = p->next;
		if (p != tail) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			current_size--;  //  Now one less
			result = true;  //  Found element and deleted it
		}
		return result;
	}

	//  Prints the elements of the list in order
	void print(std::ostream& os) const {
		os << '[';
		if (head->next != tail) {  //  List is non-empty
			for (Node *p = head->next; p->next != tail; p = p->next)
				os << p->data << ',';
			os << tail->prev->data;
		}
		os << ']';
	}

	//  Prints the elements of the list in reverse order
	void print_reverse(std::ostream& os) const {
		os << '[';
		if (tail->prev != head) { //  List is non-empty
			for (Node *p = tail->prev; p->prev != head; p = p->prev)
				os << p->data << ',';
			os << head->next->data;
		}
		os << ']';
	}
};

//  Allow the elements of the list to be displayed in an output stream
template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
	list.print(os);
	return os;
}

#endif
