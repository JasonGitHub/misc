#include <iostream>

using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

void PrintTree(BSTNode* t) {
	if (t == NULL)
		return;
	PrintTree(t->left);
	cout << t->data << endl;
	PrintTree(t->right);
}

BSTNode* FindNode(BSTNode* t, const int &data) {
	if (t == NULL)
		return NULL;
	if (data == t->data)
		return t;
	if (data < t->data)
		FindNode(t->left, data);
	else
		FindNode(t->right, data);
}

void InsertNode(BSTNode* &t, const int &data) {
	if (t == NULL) {
		t = new BSTNode;
		t->data = data;
		t->left = t->right = NULL;
	} else {
		if (data != t->data) {
  		if (data < t->data)
				InsertNode(t->left, data);
			else
				InsertNode(t->right, data);
		}
	}
}

BSTNode* CopyTree(BSTNode* t) {
	if (t == NULL)
		return NULL;
	BSTNode* n = new BSTNode;
	n->data = t->data;
	n->left = CopyTree(t->left);
	n->right = CopyTree(t->right);
	return n;
}

//TO DO
BSTNode* RemoveNode(BSTNode* t, const int data) {
	
}

bool IsBST(BSTNode* n, int lo, int hi) {
  if (n == NULL)
    return true;
  if (lo < n->data && n->data < hi) {
    return IsBST(n->left, lo, n->data) &&
           IsBST(n->right, n->data, hi);
  } else {
    return false;
  }
}

bool IsBST(BSTNode* root) {
  return IsBST(root, INT_MIN, INT_MAX);
}

//TO DO
void GenerateRandTree(BSTNode* t) {
}

BSTNode t1[] = {
 {4, &t1[1], &t1[2]},
 {2, &t1[3], &t1[4]},
 {6, &t1[5], &t1[6]},
 {1, NULL, NULL},
 {3, NULL, NULL},
 {5, NULL, NULL},
 {7, NULL, NULL}
};

int main() {
	PrintTree(t1);
  cout << IsBST(t1) << endl;
	return 0;
}
