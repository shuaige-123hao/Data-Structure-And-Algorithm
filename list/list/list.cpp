#include <iostream>
#include <stdexcept>
using namespace std;
typedef int any;
typedef struct listnode {
	listnode* next ;
	any data;
	listnode(any x) :data(x), next(NULL) {};
}node;
class linkedlist {
private:listnode* head;
	   int size;
public: linkedlist() :head(NULL), size(0) {};
	  ~linkedlist();
	  void insert(int index, any data);
	  void dele(int index);
	  listnode* find(any data);
	  listnode* get(int index);
	  void update(int index, any data);
	  void print();

public:
};
linkedlist::~linkedlist() {
	listnode* curr = head;
	while (curr) {
		listnode* temp = curr;
		curr = curr->next;
		delete temp;
	}
	cout << "析构完毕"<<endl;
}
void linkedlist::insert(int index, any data) {
	if (index<0 || index>size) {
		throw std::out_of_range("Invalid index");
	}
	listnode* temp = new listnode(data); 
	listnode* curr = head;

	if (index == 0) {
		temp->next = head;
		head = temp;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			curr = curr->next;
		}
		temp->next = curr->next;
		curr->next = temp;
	}
	size++;
};
void linkedlist::dele(int index) {
	if (index<0 || index>size) {
		throw std::out_of_range("Invalid index");
	}
	if (index == 0) {
		listnode* temp = head;
		head = head->next;
		delete temp;
	}
	else {
		listnode* curr = head;
		for (int i = 0; i < index - 1; i++) {
			curr = curr->next;
		}
		listnode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	--size;
};
listnode* linkedlist:: find(any data) {
	listnode* curr = head;
	while (curr) {
		if (curr->data == data) {
			cout << "找到了";
			return curr;
		}
		curr = curr->next;
	}
	cout << "没找到";
	return NULL;
}
listnode*linkedlist:: get(int index) {
	listnode* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr;
}
void linkedlist::update(int index, any data) {
	listnode* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	curr->data = data;
}
void linkedlist::print() {
	listnode* curr = head;
	while(curr){
		cout << curr->data<<"   ";
		curr = curr->next;
	}
	cout << endl;
}



int main() {
	linkedlist l;
	for (int i = 0; i < 10; i++) {
		l.insert(i, i);
	}
	l.print();
	l.update(0, 100);
	l.dele(4);
	l.find(999);
	l.update(5, 778);
	cout << endl;
	cout << l.get(3)->data<<endl;
	l.print();




	return 0;
}