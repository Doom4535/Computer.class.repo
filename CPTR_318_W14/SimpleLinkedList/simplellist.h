#ifndef _DEFINED_SIMPLELLIST_H_
#define _DEFINED_SIMPLELLIST_H_

#include <iostream>

//  Represents an ordered doubly-linked list
template <typename T>
class List {
protected:
    struct Node {
        T data;            //  The data of interest
        Node *next;		   //  Link to successor node
        Node *prev;		   //  Link to predecessor node
    };

    Node *head, *tail;	   //  Pointers to the first and last elements of the list

    int current_size;	   //  Number of elements in the list

    //  Copy constructor inaccessible to clients
    List(const List<T>& other);
    //  Assignment inaccessible to clients
    List<T>& operator=(const List<T>& other);
public:
    List(): head(nullptr), tail(nullptr), current_size(0) {}

    ~List() {   //  Free up the space held by the list
        Node *p = head;
        while (p != tail) {
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

	//  Inserts elem into its proper place within
	//  the list
    void insert(const T& elem) {
        //  Find location to insert the element
        Node *p = head;
        while (p && p->data < elem)
            p = p->next;

        //  Allocate new node and assign data
        Node *new_node = new Node;
        new_node->data = elem;

        //  Determine how to link the new node into the list
        if (!p) {   //  p is null (went off the back of the list)
            if (tail) {   //  List not empty; new node goes on back
                new_node->prev = tail;
                new_node->next = nullptr;
                tail->next = new_node;
                tail = new_node;
            }
            else {  //  List empty, new node becomes the only node in the list
                head = tail = new_node;
                new_node->next = new_node->prev = nullptr;
            }
        }
        else {  //  p is non-null; it's somewhere before the end
            if (p == head) {  //  Insert on front of non-empty list
                new_node->next = head;
                new_node->prev = nullptr;
                head->prev = new_node;
                head = new_node;
            }
            else {  //  Inserting after head, before tail
                p->prev->next = new_node;
                new_node->next = p;
                new_node->prev = p->prev;
                p->prev = new_node;
            }
        }
        current_size++;    //  Adjust size
    }

	//  Removes elem from the list, if possible.
	//  Returns true if successful; otherwise, returns false.
    bool remove(const T& elem) {
        //  Find element to remove
        bool result = false;  //  Fail by default
        Node *p = head;
        while (p && p->data != elem)
            p = p->next;
        if (p) {  //  Found it
            if (p == head && p == tail)    //  Remove only element
                head = tail = nullptr;
            else if (p == head) {          //  Remove first element
                head = p->next;
                head->prev = nullptr;
            }
            else if (p == tail) {          //  Remove last element
                tail = p->prev;
                tail->next = nullptr;
            }
            else {                         //  Remove middle element
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;        //  Free up memory held by the list node
            current_size--;  //  Now one less
            result = true;  //  Found element and deleted it
        }
        return result;
    }

	//  Prints the elements of the list in order
    void print(std::ostream& os) const {
        os << '[';
        if (head) {  //  List is non-empty
            for (Node *p = head; p != tail; p = p->next)
                os << p->data << ',';
            os << tail->data;
        }
        os << ']';
    }

	//  Prints the elements of the list in reverse order
    void print_reverse(std::ostream& os) const {
        os << '[';
        if (tail) {  //  List is non-empty
            for (Node *p = tail; p != head; p = p->prev)
                os << p->data << ',';
            os << head->data;
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
