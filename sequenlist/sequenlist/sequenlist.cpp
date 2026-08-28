#include <iostream>
using namespace std;
#define anytype int
typedef struct sequenlist{
anytype* elements;
int size;
int capacity;
}sq;
void innitialize(sq* l,int capacity) {
	l->capacity = capacity;
	l->size = 0;
	l->elements = new anytype[capacity];
}
void destroy(sq* l) {
	delete []l->elements;
}
int getsize(sq* l) {
	return l->size;
}
bool isempty(sq* l) {
	return l->size == 0;
}
void insert(sq* l, int index, int data) {
	if (index<0 || index>l->size) {
		throw std::invalid_argument("Invalid_index");
	}
	if (l->size == l->capacity) {
		int temp = l->capacity * 2;
		anytype* newelements = new anytype[temp];
		for (int i = 0; i < l->size; i++) {
			newelements[i] = l->elements[i];
		}
		delete[]l->elements;
		l->elements = newelements;
		l->capacity = temp;
	}
	
	else {
		for(int i=l->size;i>index;i++){
			l->elements[i] = l->elements[i - 1];
		}
		l->elements[index] = data;
	}
	l->size++;
}
void dedata(sq* l, int index) {
	if (index < 0 || index >= l->size - 1) {
		throw std::invalid_argument("Invalid_index");
	}
	else {
		for (int i = index; i+1 <l->size; i++) {
			l->elements[i] = l->elements[i + 1];
		}
	}
	l->size--;
}
int find(sq* l, anytype data) {
	for (int i = 0; i < l->size; i++) {
		if (l->elements[i] == data)return i;
	}
	return -1;
}
anytype getdata(sq* l,int  index) {
	return l->elements[index];
}
void update(sq* l, int index, anytype newdata) {
	if (index < 0 || index >= l->size) {
		throw std::invalid_argument("Invalid_index");
	}
	l->elements[index] = newdata;
}
void print(sq* l) {
	for (int i = 0; i < l->size; i++) {
		cout << l->elements[i] << "  ";
	}
	cout << endl;
}



int main() {
	sq a;
	innitialize(&a,5);
	insert(&a, 0, 9);
	insert(&a, 1, 8);
	insert(&a, 2, 5);
	print(&a);
	update(&a, 0, 6);
	print(&a);
	cout <<"index 为2的元素"<< getdata(&a, 2)<<endl;
	cout << "是否为空"<<isempty(&a)<<endl;
	cout << "是否查找到" << find(&a, 100)<<endl;
	dedata(&a, 1);
	cout << "a的大小" << getsize(&a)<<endl;
	print(&a);
	destroy(&a);
	return 0;
}