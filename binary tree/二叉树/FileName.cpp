#include <iostream>
using namespace std;
template <typename T>
struct treenode {
	treenode* left;
	treenode* right;
	T val;
	treenode() :val(0), left(NULL), right(NULL) {};
	treenode(T x):val(x), left(NULL), right(NULL) {};
};
template <typename T>
class Tree {
private:
	treenode<T>* nodes;
	treenode<T>* root;
	size_t nodesizes;
	treenode <T>* Create(T a[], int size, int nodeid, T nullnode);
	void visit(treenode<T>* node);
	void preorder(treenode<T>* node);
	void inorder(treenode<T>* node);
	void postorder(treenode<T>* node);
	void levelorder(treenode<T>* node);
public:Tree();
	  Tree(int max);
	  ~Tree();
	  treenode<T>* getnode(int id);
	  void createtree(T a[], int size,T nullnode);
	  void preorder();
	  void inorder();
	  void postorder();
	  void levelorder();
};

template <typename T>
treenode <T>* Tree<T>::Create(T a[], int size, int nodeid, T nullnode) {
	if (nodeid >= size || a[nodeid] == nullnode) {
		return NULL;
	}
	 treenode<T>* node1 = new treenode<T>;
	 node1->val = a[nodeid];
	 node1->left = Create(a, size, nodeid * 2,  nullnode);
	 node1->right = Create(a, size, nodeid * 2+1,  nullnode);
	 return node1;
}
template <typename T>
void Tree<T>::visit(treenode<T>* node) {
	cout << node->val;
}
template <typename T>
void Tree<T>::preorder(treenode<T>* node) {
	if (node) {
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}
template <typename T>
void Tree<T>::inorder(treenode<T>* node) {
	if (node) {
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
}
template <typename T>
void Tree<T>::postorder(treenode<T>* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}
//template <typename T>
//void Tree<T>::levelorder(treenode<T>* node) {
//	
//}
template<typename T>
Tree<T>::Tree() {
	nodes = new treenode<T>[1000];
}
template <typename T>
Tree<T>::Tree(int max) {
	nodes = new treenode<T>[max];
}
template <typename T>
Tree<T>::~Tree() {
	delete[] nodes;
}

template <typename T>
treenode<T>* Tree<T>::getnode(int id) {
	return &nodes[id];
}
template <typename T>
void Tree<T>::createtree(T a[], int size,T nullnode) {
	root = Create(a,size,1, nullnode);
}

template <typename T>
void Tree<T>::preorder() {
	preorder(root);
}
template <typename T>
void Tree<T>::inorder() {
	inorder(root);
}
template <typename T>
void Tree<T>::postorder() {
	postorder(root);
}
//template <typename T>
//void Tree<T>::levelorder() {
//	levelorder(root);
//}
int main() {


	const char nullNpde = '-';
	char a[15] = {
		nullNpde, 'a', 'b', 'c', 'd',
		nullNpde, 'e', 'f', 'g', 'h',
		nullNpde, nullNpde, nullNpde, nullNpde, 'i'
	};

	Tree<char> T(15);
	T.createtree(a, 15, nullNpde);
	T.preorder(); cout << endl;
	T.inorder(); cout << endl;
	T.postorder(); cout << endl;



	return 0;
}
