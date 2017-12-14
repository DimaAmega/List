#include "list.h"
List:: List() {
	Head = NULL;
}

List:: List(const List& list2) {
	if (list2.Head != NULL) {
		Node* ptr = list2.Head->next;
		Head =  new Node(list2.Head->data,NULL);
		Node* ptr2 = Head;
		while (ptr!= NULL) {
			ptr2->next = new Node(ptr->data,NULL);
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
	}  else Head = NULL;
}



List& List:: operator=(const List& list2) {
	Clean();
	if (list2.Head != NULL) {
		Node* ptr = list2.Head->next;
		Head = new Node(list2.Head->data, NULL);
		Node* ptr2 = Head;
		while (ptr != NULL) {
			ptr2->next = new Node(ptr->data, NULL);
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
		return *this;

	} 

}

void List::Clean() {
	if (Head != NULL) {
		if (Head->next != NULL) {
			Node* Ptr = Head->next->next;
			Node* Ptr_before = Head->next;
			delete Head;
			while (Ptr != NULL) {
				delete Ptr_before;
				Ptr_before = Ptr;
				Ptr = Ptr->next;
			}
			delete Ptr_before;
		} else {
			delete Head;
			Head = NULL;
		}
	}
}


void List::InserToHead(const DataType& d) {

	if (Head == NULL) Head = new Node(d, NULL);
	else Head = new Node(d, Head);
}

void List::InserToTail(const DataType& d) {
	if (Head == NULL) Head = new Node(d, NULL);
	else {
		Node* ptr = Head;
		while (ptr != NULL) ptr = ptr->next;
		ptr->next = new Node(d, NULL);
	}
}