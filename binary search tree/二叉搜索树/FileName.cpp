#include <iostream>
using namespace std;
template<typename T>
struct treenode {
	T val;
	treenode* left;
	treenode* right;
	treenode() :val(0), left(NULL), right(NULL) {};
	treenode(T x) :val(x), left(NULL), right(NULL) {};
};


template<typename T>
class SBTree{
private:
	treenode<T>* root;
	treenode<T>* removenode(treenode<T>* root, T val);
	treenode<T>* insert(treenode<T>* root, T val);
	bool searchnode(treenode<T>* root, T val);
	void inorder(treenode<T>* root);
public:
	SBTree() :root(NULL) {};
	~SBTree();
	void Removenode(T val) {
		root = removenode(root, val);
	}
	void Insert(T val) {
		root = insert(root, val);
	}
	bool Searchnode( T val) {
		return searchnode(root, val);
	}
	void Inorder() {
		inorder(root);
		cout << endl;
	}

};
template<typename T>
SBTree<T>::~SBTree() {
	while (root) {
		Removenode(root->val);
	}
}

template<typename T>
treenode<T>* SBTree<T>::removenode(treenode<T>* root, T val) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->val > val) {
		root->left = removenode(root->left, val);
		
	}
	else if (root->val < val) {
		root->right = removenode(root->right, val);
		
	}
	else {
		if (root->left == NULL && root->right== NULL) {
			return NULL;
		}
		else if (root->left == NULL) {
			treenode<T>* temp = root->right;
			delete root;
			root = temp;
			
		}
		else if (root->right == NULL) {
			treenode<T>* temp = root->left;
			delete root;
			root = temp;
			
		}
		else {
			treenode<T>* temp = root->right;
			while (temp->left) {
				temp = temp->left;
			}
			root->val = temp->val;
			root->right = removenode(root->right, temp->val);
			
		}
	}
	return root;
}

template<typename T>
treenode<T>* SBTree<T>::insert(treenode<T>* root, T val) {
	if (root == NULL) {
		return new treenode<T>(val);
	}
	if (val > root->val) {
		root->right=insert(root->right, val);
	}
	else {
		root->left=insert(root->left, val);
	}
	return root;
}

template<typename T>
bool SBTree<T>::searchnode(treenode<T>* root, T val) {
	if (root == NULL) {
		return  false;
	}
	if (val > root->val) {
		return searchnode(root->right, val);
	}
	else if(val<root->val) {
		return searchnode(root->left, val);
	}
	return true;
}
template<typename T>
void SBTree<T>::inorder(treenode<T>* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->val<<' ';
	inorder(root->right);
}

int main() {

	SBTree<int> bst;

	bst.Insert(50);
	bst.Insert(30);
	bst.Insert(70);
	bst.Insert(40);
	bst.Insert(80);
	bst.Insert(60);
	bst.Insert(100);

	cout << "中序遍历：";
	bst.Inorder();
	cout << "查找 100：" << bst.Searchnode(100) << endl;
	cout << "查找 50：" << bst.Searchnode(50) << endl;

	bst.Removenode(70);
	cout << "中序遍历：";
	bst.Inorder();

	bst.Insert(65);
	cout << "中序遍历：";
	bst.Inorder();

	return 0;
}