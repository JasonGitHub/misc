// Mirror the tree itself
void MirrorTree(Node* n) {
  if (n == NULL) return;
  Node* tmp = n->left;
  n->left = n->right;
  n->right = tmp;
  MirrorTree(n->left);
  MirrorTree(n->right);
}

// Check if a tree if the mirror of another
bool CheckMirror(Node* n1, Node* n2) {
  if (n1 == NULL && n2 == NULL) return true;
  return n1 != NULL && n2 != NULL &&
    n1->val == n2->val &&
    CheckMirror(n1->left, n2->right) &&
    CheckMirror(n1->right, n2->left); 
}

// Get a Mirror of the original
void GetMirror(Node* n1, Node* n2) {
  if (n1 == NULL || n2 == NULL) return;
  n2->val = n1->val;
  if (n1->left) {
    n2->right = new Node();
    GetMirror(n1->left, n2->right);
  }
  if (n1->right) {
    n2->left = new Node();
    GetMirror(n1->right, n2->left);
  }
}

Node* GetMirror(Node* root) {
  Node* ret = new Node();
  GetMirror(root, ret);
  return ret;
}

void PrintBinaryTree(Node* root) {
  if (root == NULL) return;
  queue<Node*> curr, next;
  curr.push(root);
  while (!curr.empty()) {
    Node* n = curr.front(); 
    curr.pop();
    cout << n->val << " ";
    if (n->left) next.push(n->left);
    if (n->right) next.push(n->right);
    if (curr.empty()) {
      cout << endl;
      swap(curr, next);
    }
  }
}
