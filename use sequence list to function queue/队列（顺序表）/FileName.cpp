#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T>
class queue{
private:
	T* elements;
	int front;
	int rear;
	int capacity;
	void resize();
public:
	queue() : elements(new T[10]), front(0), rear(0), capacity(10){};
	  ~queue();
	  T deque();
	  void enqueue(T data);
	  T getfront()const;
	  T getsize()const;
};
template<typename T>
void queue<T>::resize() {
	int newcapacity = capacity * 2;
	T* newdatas = new T[newcapacity];
	for (int i = 0; i < capacity; i++) {
		newdatas[i] = elements[i];
	}
	delete []elements;
	elements = newdatas;
	capacity = newcapacity;
}
template <typename T>
queue<T>::~queue() {
	delete []elements;
}
template <typename T>
T queue<T>::deque() {
	if (rear == front) {
		throw std::underflow_error("invalid operation");
	}
	front++;
	return elements[front-1];
}
template <typename T>
void queue<T>::enqueue(T data) {
	if (rear ==capacity) {
		resize();
	}
	elements[rear] = data;
	rear++;
}
template <typename T>
T queue<T>::getfront()const {
	if (rear == front) {
		throw std::underflow_error("invalid operation");
	}
	return elements[front];
}
template <typename T>
T queue<T>::getsize()const {
	return rear - front;
}
int main() {
	queue<int> que;
	que.enqueue(3);
	que.enqueue(4);
	cout << que.getfront() << endl;
	que.enqueue(5);
	cout << que.getfront() << endl;
	que.deque();
	cout << que.getfront() << endl;
	cout << que.getsize() << endl;




	return 0;
}