#include <iostream>
using namespace std;
template <typename keytype ,typename valuetype>
class hashnode {
public:
	keytype key;
	valuetype value;
	hashnode* next;
	hashnode(keytype key, valuetype value) :key(key), value(value), next(NULL) {};
};
template <typename keytype, typename valuetype>
class hashtable {
private:
		int size;
		hashnode<keytype, valuetype>** nodes;
		int hash(const keytype& key) const{
			int hashkey = key % size;
			if (hashkey < 0) {
				hashkey =hashkey+size;
			}
			return hashkey;
		}
public:
	hashtable(int size);
	~hashtable();
	void insert(const keytype& key,const valuetype& value);
	void remove(const keytype& key);
	// 在哈希表中查找指定键的值
	bool find(const keytype& key, valuetype& value) const;

};

template <typename keytype, typename valuetype>
hashtable<keytype, valuetype>::hashtable(int size) {
	this->size = size;
	nodes = new hashnode< keytype, valuetype>* [size];
	for (int i = 0; i < size; i++) {
		nodes[i] = NULL;
	}
}
template <typename keytype, typename valuetype>
hashtable<keytype, valuetype>::~hashtable() {
	for (int i = 0; i < size; i++) {
		if (nodes[i]) {
			hashnode< keytype, valuetype>* temp = nodes[i];
			while (temp) {
				hashnode< keytype, valuetype>* t =temp;
				temp = temp->next;
				delete t;
				t = NULL;
			}
		}
	}
	delete []nodes;
	nodes = NULL;
}
template <typename keytype, typename valuetype>
void hashtable<keytype, valuetype>::insert(const keytype& key, const valuetype& value) {
	hashnode< keytype, valuetype>* temp = new hashnode< keytype, valuetype>(key, value);
	int c = hash(key);
	temp->next = nodes[c];
	nodes[c] = temp;
	return;
}
template <typename keytype, typename valuetype>
void hashtable<keytype, valuetype>::remove(const keytype& key) {
	int c = hash(key);
	if (nodes[c] == NULL) {
		return ;
	}
	else {
		if (nodes[c]->key == key) {
			hashnode< keytype, valuetype>* temp = nodes[c];
			nodes[c] = temp->next;
			delete temp;
		}
		hashnode< keytype, valuetype>* pre = nodes[c];
		while (pre->next) {
			if (pre->next->key == key) {
				hashnode< keytype, valuetype>* help = pre->next;
				pre->next = pre->next->next;
				delete help;
				return;
			}
			else pre = pre->next;
		}
	}
	return;
}
// 在哈希表中查找指定键的值
//这个函数后面跟了const只能调用const函数，所以前面的hash函数也要加const限定
template <typename keytype, typename valuetype>
bool hashtable<keytype, valuetype>::find(const keytype& key, valuetype& value) const{
	int c = hash(key);
	if (nodes[c])
	{
		if (nodes[c]->key == key) {
			value = nodes[c]->value;
			return true;
		}
	}
	if (nodes[c]) {
		hashnode< keytype, valuetype>* temp = nodes[c];
		while (temp) {
			if (temp->key == key) {
				value = temp->value;
				return true;
			}
			else temp = temp->next;
		}
	}
	return false;
}
template<typename T>
class hashcounter {
private:
	int* counter;
	int indexnow;
	int capacity;
	hashtable<T, int>* ha;
public:
	hashcounter(int size = 1000);
	void reset();
	~hashcounter();
	int add(const T& t);
	int sub(const T& t);
	int getf(const T& t)const;
};
template<typename T>
hashcounter<T>::hashcounter(int size) {
	counter = new int[size];
	indexnow = 0;
	capacity = size;
	ha = NULL;
	reset();
}
template<typename T>
void hashcounter<T>::reset() {
	if (ha) {
		delete ha;
		ha= NULL;
	}
	ha = new hashtable<T, int>(capacity);
	for (int i = 0; i < capacity; i++) {
		counter[i] = 0;
	}
}
template<typename T>
hashcounter<T>::~hashcounter() {
	delete[]counter;
	delete ha;
	counter = NULL;
	ha = NULL;
}
template<typename T>
int hashcounter<T>::add(const T& t) {
	int val;
	if (!ha->find(t, val)) {
		val = indexnow++;
		ha->insert(t, val);
	}
	return ++counter[val];
}
template<typename T>
int hashcounter<T>::sub(const T& t) {
	int val;
	if (ha->find(t, val)) {
		return --counter[val];
	}
	return 0;
}
template<typename T>
int hashcounter<T>::getf(const T& t)const {
	int val;
	if (ha->find(t, val)) {
		return counter[val];
	}
	return 0;
}

int main() {


	hashtable<int, char> h(100);
	h.insert(1, 'a');
	h.insert(2, 'b');
	h.insert(3, 'c');
	h.insert(41012012, 'd');
	h.insert(101, 'f');
	
	char val;
	if (!h.find(43, val)) {
		cout << "43 not found!" << endl;
	}
	if (h.find(41012012, val)) {
		cout << "41012012 found, value is " << val << endl;
	}
	if (h.find(1, val)) {
		cout << "1 found, value is " << val << endl;
	}

	hashcounter<int>  s(100);
	s.add(14);
	s.add(14);
	s.add(14);
	s.add(14);
	//s.sub(14);
	s.add(14);
	cout << s.getf(14) << endl;

	return 0;
}