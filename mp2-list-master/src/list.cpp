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

List:: ~List() {
	Clean();
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
		return (*this);

	} 

}

void List::Clean() {
	if (Head != NULL) {
		if (Head->next != NULL) {
			Node* Ptr = Head->next->next;
			Node* Ptr_before = Head->next;
			delete Head;
			Head = NULL;
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


void List::InsertToHead(const DataType& d) {

	if (Head == NULL) Head = new Node(d, NULL);
	else Head = new Node(d, Head);
}

void List::InsertToTail(const DataType& d) {

	if (Head == NULL) Head = new Node(d, NULL);

	else {
		Node* ptr = Head;
		while (ptr->next!=NULL) ptr = ptr->next;
		ptr->next = new Node(d, NULL);
	}
}

void List::InsertAfter(Node* node, const DataType& d) {
	if (node == NULL) {
		this->InsertToTail(d);
	}
	else {
		Node* ptr = Head;
		while (node != ptr) ptr = ptr->next;
		Node* ptr2 = node->next;
		ptr->next = new Node(d, ptr2);
	}
}

void List::Delete(const DataType& d) {
	int y = 0;
	Node* ptr_prev = Head;
	if (Head != NULL) {
		Node* ptr = Head;
		if (ptr->data != d) {
			ptr = ptr->next;
		} else {
			y = 1;
			Node* ptr_Head = Head->next;
			delete Head;
			Head = ptr_Head;
		}
		if (y == 0) {
			while ((ptr != NULL) && (ptr->data != d)) {
				ptr = ptr->next;
				ptr_prev = ptr_prev->next;
			}
			if (ptr == NULL) cout << "uncorrect, is is valtype no here" << endl; else {
				ptr_prev->next = ptr->next;
				delete ptr;
			}
		}
	}
}


Node* List::Search(const DataType& d) {
	//Проверка на наличие циклов

	//Проверка на наличие циклов
	Node* ptr = Head;
	while ((ptr != NULL)&&(ptr->data != d)) ptr= ptr->next;
	if (ptr == NULL) return NULL; else return ptr;
}

int List:: GetSize() const {
	Node* ptr = Head;
	int k = 0;
	while (ptr != NULL) {
		k++;
		ptr = ptr->next;
	}
	return k;
}


Node* List:: GetHead() {
	return Head;
}

void List:: Inverse() {
	Node* ptr_1 = Head;
	Node* ptr_2;
	Node* ptr_3;
	if (Head != NULL) {
		ptr_2 = Head->next;
		Head->next = NULL;
		if(ptr_2!=NULL){ 
		ptr_3 = ptr_2->next; 
		while (ptr_3 != NULL) {
			ptr_2->next = ptr_1;
			ptr_1 = ptr_2;
			ptr_2 = ptr_3;
			ptr_3 = ptr_3->next;
		}
		ptr_2->next = ptr_1;
		Head = ptr_2;
		}
	}
}


List List::Merge(Node* node, const List& list2)// создать список3, добавив список2 в текущий список после указателя node  
{  
	List a;
	Node* ptr = Head;
	if (node != NULL) {
		while (ptr != node) {
			a.InsertToTail(ptr->data);
			ptr = ptr->next;
		}
		a.InsertToTail(ptr->data);
		ptr = ptr->next;
		Node* ptr_2 = list2.Head;
		while (ptr_2!= NULL) {
			a.InsertToTail(ptr_2->data);
			ptr_2 = ptr_2->next;
		}
		while (ptr != NULL) {
			a.InsertToTail(ptr->data);
			ptr = ptr->next;
		}
		return a;
	}
	else {
		a = (*this);
		//a = a.Merge(list2);
		return a;
	}
}


List List:: Merge(const List& list2) // создать список3, добавив в конец текущего списка список2
{
	List a;
	Node* ptr = Head;
	while (ptr != NULL) {
		a.InsertToTail(ptr->data);
		ptr = ptr->next;
	}
	ptr = list2.Head;
	while (ptr != NULL) {
		a.InsertToTail(ptr->data);
		ptr = ptr->next;
	}
	return a;
}


ostream& operator<<(ostream& os, const List& l) {
	Node* ptr = l.Head;
	os << "quality is" <<l.GetSize()<<endl;
	if (ptr == NULL) cout << "This list is clear" << endl; else {
		while (ptr != NULL) {
			os << "|" << ptr->data<< "|";
			ptr = ptr->next;
		}
		os << endl;
	}
	return os;
}

 bool List:: operator ==(const List& list2) const {

	 Node* ptr_1 = Head;
	 Node* ptr_2 = list2.Head;
	 while ((ptr_1 != NULL) && (ptr_2 != NULL)&&(ptr_1->data == ptr_2->data)) {
		 ptr_1 = ptr_1->next;
		 ptr_2 = ptr_2->next;
	 }
	 if ((ptr_1 == NULL) && (ptr_2 == NULL)) return true;
 else return false;
 }