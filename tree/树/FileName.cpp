//信息量大时用树来辅助分类帮助我们快速思考


#include <iostream>
using namespace std;
template <typename T>
struct listnode {
	T dataregion;
	listnode* next;
	listnode(T d) :dataregion(d), next(NULL) {};
};
template <typename T>
struct treenode {
	T data;
	listnode < treenode<T>* > *childhead;
	treenode() {
		childhead = NULL;
	}
	void addchild(treenode<T>* node) {
		listnode<treenode<T>*>* child = new listnode<treenode<T>*>(node);
		if (childhead == NULL) {
			childhead = child;
		}
		else {
			child->next = childhead;
			childhead= child;
		}
	}
};
template <typename T>
class Tree{
private:
	treenode<T>* nodes;
	treenode<T>* root;
public:
	Tree();
	Tree(int capacity);
	~Tree();
	treenode<T>* getnode(int id);
	void setroot(int id);
	void Addchild(int pid, int cid);
	void assign(int id, int data);
	void pr(treenode <T>* node=NULL);


};
template <typename T>
Tree<T>::Tree() {
	nodes = new treenode<T>[10000];
}
template <typename T>
Tree<T>::Tree(int capacity) {
	nodes = new treenode<T>[capacity];
}
template <typename T>
Tree<T>::~Tree() {
	delete[]nodes;
}
template <typename T>
treenode<T>* Tree<T>::getnode(int id) {
	return &nodes[id];
}
template <typename T>
void Tree<T>::setroot(int id) {
	root =& nodes[id];
}
//template <typename T>
//void Tree<T>::Addchild(int pid, int cid) { 
//	nodes[pid].addchild(getnode(cid));
//}

template<typename T>
void Tree<T>::Addchild(int pid, int cid) {
	treenode<T>* parentNode = getnode(pid);
	treenode<T>* sonNode = getnode(cid);
	parentNode->addchild(sonNode);
}

template <typename T>
void Tree<T>::assign(int id, int data) {
	getnode(id)->data = data;
}
template <typename T>
void Tree<T>::pr(treenode <T>* node ) {
	if (node == NULL) {
		node = root;
	}
	cout << node->data;
	listnode<treenode<T>*>* tmp = node->childhead;
	while (tmp) {
		pr(tmp->dataregion);
		tmp = tmp->next;
	}
}
int main() {
	Tree<char> T(9);
	T.setroot(0);
	T.assign(0,'a');
	T.assign(1, 'b');
	T.assign(2,'c');
	T.assign(3, 'd');
	T.assign(4, 'e');
	T.assign(5,'f');
	T.assign(6,'g');
	T.assign(7,'h');
	T.assign(8,'i');
	T.Addchild(0,2);
	T.Addchild(0,1);
	T.Addchild(1,3);
	T.Addchild(2,5);
	T.Addchild(2,4);
	T.Addchild(3,8);
	T.Addchild(3,7);
	T.Addchild(3, 6);
	T.pr();

	return 0;
}