#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class queue{
private:
	struct listnode {
		listnode* next;
		T data;
		listnode(T d) :next(NULL), data(d) {};
     };
	listnode* front;
	listnode* rear;
	int size;
public:
	queue() :front(NULL), rear(NULL), size(0) {};
	~queue();
	void enqueue(T data);
	T dequeue();
	T getqueue()const;
	int getsize()const;
};
template<typename T>
queue<T>::~queue() {
	while (front) {
		listnode* temp = front;
		front = front->next;
		delete temp;
	}
	
}
template<typename T>
void queue<T>::enqueue(T data) {
	if (rear == NULL) {
		rear = new listnode(data);
		front = rear;
	}
	else {
		rear->next = new listnode(data);
		rear = rear->next;
	}
	++size;
}
template<typename T>
T queue<T>::dequeue() {
	if (front == NULL) {
		throw std::underflow_error("invalid operation");
	}
	
		T da = front->data;
		listnode* temp = front;
		front = front->next;
		delete temp;
	    --size;
	if (size == 0) {
		rear = NULL;
	}
	return da;
}
template<typename T>
T queue<T>::getqueue()const {
	if (front == NULL) {
		throw std::underflow_error("invalid operation");
	}
	return front->data;
}
template<typename T>
int queue<T>::getsize()const {
	return size;
}




int main() {
	queue <int> q;
	q.enqueue(3);
	q.enqueue(4);
	cout << q.getqueue() << endl;
	q.enqueue(5);
	q.dequeue();
	cout<< q.getqueue() << endl;
	cout << q.getsize() << endl;

	return 0;
}