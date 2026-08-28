#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class stack {
private:
	T* elements;
	int size;
	int capacity;
	void resize();
public:
	stack() :capacity(2), size(0), elements(new T[10]) {

	}
	~stack();
	void push(T element);
	T pop();
	int getsize ()const;
	T getdata ()const;
};

template<typename T>

void stack<T>:: resize() {
	int newcapacity = capacity * 2;
	T* newelements = new T[newcapacity];
	for (int i = 0; i < size; i++) {
		newelements[i] = elements[i];
	}
	delete[]elements;
	elements = newelements;
	capacity = newcapacity;
}
template <typename T>
 stack<T>::~stack() {
	 delete[]elements;
}
 template <typename T>
 void stack<T>::push(T element) {
	 if (size == capacity) {
		 resize();
	 }
	 elements[size] = element;
	 size++;
 }
 template <typename T>
 T stack<T>::pop() {
	 if (size == 0) {
		 throw std::underflow_error("stack is empty");
	 }
	 size--;
	 return elements[size];
 }
 template <typename T>
 int stack<T>::getsize ()const {
	 return size;
}
template <typename T>
T stack<T>::getdata ()const {
	if (size == 0) {
		throw std::underflow_error("stack is empty");
	}
	return elements[size-1];
}

int main() {
	stack<int> sk;
	sk.push(4);
    sk.push(7);
	sk.push(13);
	cout << sk.getdata() << endl;
	sk.push(17);
	cout << sk.getdata() << endl;
	sk.pop();
	sk.pop();
	cout<< sk.getdata() << endl;
	cout << sk.getsize();
	






	return 0;
}