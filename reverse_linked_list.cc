// recursive
Node* ReverseLinkedList(Node* n, Node* prev) {
  if (n == NULL) return prev;
  Node* tmp = n->next;
  n->next = prev;
  return ReverseLinkedList(tmp, n);
}
Node* ReverseLinkedList(Node* n) {
  return ReverseLinkedList(n, NULL);
} 

// iterative
Node* ReverseLinkedListIterative(Node* n) {
  Node* tmp;
  Node* prev = NULL;
  while (n != NULL) {
    tmp = n->next;
    n->next = prev;
    prev = n;
    n = tmp;
  }
  return prev;
}
