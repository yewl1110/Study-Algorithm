#include <iostream>
#define LARGE 1
#define EQUAL 0
#define SMALL -1
#define compare(x,y) (x==y?EQUAL:x>y?LARGE:SMALL)
using namespace std;

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

class AVLTree {
	Node* root;
public:
	AVLTree() { root = NULL; }
	void preorder(Node* node);
	void preorder() { preorder(root); }
	void insert(int data);
	void remove(int data);
	Node* getParent(Node* pivot);
	int getHeight(Node* node, int depth);
	int getBalance(Node* node);
	int getBalance() { return getBalance(root); }
	bool check(Node* node);
	void check() { while (true) { if (!check(root)) break; } }
	void rotate(Node* subRoot);
	void rrotate(Node* subRoot);
	void lrotate(Node* subRoot);
};

int main() {
	AVLTree avl;
	int n;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		avl.insert(n);
		avl.preorder();
		cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		cin >> n;
		avl.remove(n);
		avl.preorder();
		cout << endl;
	}
}

void AVLTree::preorder(Node* node)
{
	if (!node) return;
	cout << node->data;
	if (node->left) cout << " ----\tLEFT : " << node->left->data;
	else  cout << " ----\tLEFT : NULL";
	if (node->right) cout << "\tRIGHT : " << node->right->data;
	else  cout << "\tRIGHT : NULL";
	cout << endl;
	preorder(node->left);
	preorder(node->right);
}

void AVLTree::insert(int data)
{
	if (!root) {
		root = (Node*)calloc(1, sizeof(Node));
		root->data = data;
	}
	else {
		Node* node = root, * parent = NULL;
		while (node) {
			parent = node;
			if (node->data > data) node = node->left;
			else if (node->data < data)  node = node->right;
			else return;
		}
		node = (Node*)calloc(1, sizeof(Node));
		node->data = data;
		if (parent->data > data) parent->left = node;
		else parent->right = node;
	}
	check();
}

void AVLTree::remove(int data)
{
	Node* node = root;
	Node* parent, * n_node, * np_node; 
	// parent : 삭제할 노드의 부모 노드, n_node : 삭제한 자리에 가져올 노드, np_node : n_node의 원래 부모
	while (node && node->data != data) { // 삭제할 노드 찾아감
		switch (compare(node->data, data)) {
		case LARGE: node = node->left; break;
		case SMALL: node = node->right;
		}
	}
	if (!node) return;

	parent = getParent(node);
	if (!node->left && !node->right) { //리프노드일 때
		if (parent) { 
			switch (compare(parent->data, node->data)) {
			case LARGE: parent->left = NULL; break;
			case SMALL: parent->right = NULL;
			}
		}
		else this->root = NULL; // root노드 한개만 남았을 때
		free(node);
		check();
		return;
	}
	else if (node->left) {
		n_node = node->left;
		while (n_node->right) {
			n_node = n_node->right;
		}
		if (n_node == node->left) n_node->right = node->right; // 새로 가져올 노드가 삭제 할 노드의 자식일 때
		else {
			np_node = getParent(n_node);
			np_node->right = n_node->left;
			n_node->right = node->right;
			n_node->left = node->left;
		}
	}
	else {
		n_node = node->right;
		while (n_node->left) {
			n_node = n_node->left;
		}
		if (n_node == node->right) n_node->left = node->left; // 새로 가져올 노드가 삭제 할 노드의 자식일 때
		else { 
			np_node = getParent(n_node);
			np_node->left = n_node->right;
			n_node->right = node->right;
			n_node->left = node->left;
		}
	}

	if (parent) { // 삭제된 노드의 부모노드와 새로 가져온 노드 연결 root 노드 삭제 아님
		switch (compare(parent->data, n_node->data)) {
		case LARGE: parent->left = n_node; break;
		case SMALL: parent->right = n_node;
		}
	}
	else this->root = n_node; // root노드 삭제했을 때
	free(node);
	check();
}

Node* AVLTree::getParent(Node* pivot)
{
	Node* node = root, * parent = NULL;
	if (node->data == pivot->data) return NULL;

	while (node && node->data != pivot->data) {
		parent = node;
		if (node->data > pivot->data)node = node->left;
		else node = node->right;
	}
	return parent;
}

int AVLTree::getHeight(Node* node, int depth)
{
	if (!node) return depth;

	int h_left = getHeight(node->left, depth + 1);
	int h_right = getHeight(node->right, depth + 1);
	int height = (h_left > h_right) ? h_left : h_right;
	return height;
}

int AVLTree::getBalance(Node* node)
{
	if (!node) return 0;

	int left = (node->left == NULL) ? 0 : getHeight(node->left, 0);
	int right = (node->right == NULL) ? 0 : getHeight(node->right, 0);
	return left - right;
}

bool AVLTree::check(Node* node)
{
	if (!node) return false;
	bool c1 = check(node->left);
	bool c2 = check(node->right);
	int balance = getBalance(node);
	if (balance >= 2 || balance <= -2) {
		rotate(node);
		return true;
	}
	return c1 || c2;
}

void AVLTree::rotate(Node* subRoot)
{
	int balance = getBalance(subRoot);
	if (balance <= -2) {
		if (getBalance(subRoot->right) <= -1) {
			lrotate(subRoot->right);
		}
		else {
			rrotate(subRoot->right);
			lrotate(subRoot);
		}
	}
	else if (balance >= 2) {
		if (getBalance(subRoot->left) >= 1) {
			rrotate(subRoot->left);
		}
		else {
			lrotate(subRoot->left);
			rrotate(subRoot);
		}
	}
}

void AVLTree::rrotate(Node* root)
{
	Node* parent = getParent(root);

	Node* subRoot = root->left;
	root->left = subRoot->right;
	subRoot->right = root;

	if (parent) {
		if (parent->left == root) parent->left = subRoot;
		else parent->right = subRoot;
	}
	else this->root = subRoot;
}

void AVLTree::lrotate(Node* root)
{
	Node* parent = getParent(root);

	Node* subRoot = root->right;
	root->right = subRoot->left;
	subRoot->left = root;

	if (parent) {
		if (parent->left == root) parent->left = subRoot;
		else parent->right = subRoot;
	}
	else this->root = subRoot;
}
