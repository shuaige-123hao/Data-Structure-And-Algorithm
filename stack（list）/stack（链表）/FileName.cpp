#include <iostream>
using namespace std;
template<typename T>
class stack {
private:struct Node {
	Node* next;
	T data;
	Node(T d) :next(NULL), data(d) {};
};
	   Node* head;
	   int size;
public:
	stack() :head(NULL), size(0) {};
	~stack();
	void push(T d);
	T pop();
	T top()const;
	int getsize()const;
};
template<typename T>
stack<T>::~stack() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	size = 0;
}
template<typename T>
void stack <T>::push(T d) {
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
	size++;
}
template<typename T>
T stack <T>::pop() {
	if (head == NULL) {
		throw std::underflow_error("stack is empty");
	}
	T result = head->data;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
	return result;
}
template<typename T>
T  stack <T>::top()const {
	if (head == NULL) {
		throw std::underflow_error("stack is empty");
	}
	return head->data;
}
template<typename T>
int  stack <T>::getsize()const {
	return size;
}


int main() {
	stack<int> m;
	m.push(4);
	m.push(7);
	m.push(13);
	cout << m.top() << endl;
	cout << m.pop() << endl;
	cout << m.getsize() << endl;
	return 0;
}