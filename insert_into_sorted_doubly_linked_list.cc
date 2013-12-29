// Time: O(n) Space: O(1)
Node* SortedInsert(Node* head, int val) {
    Node* n = new Node; n->val = val;
    Node* curr = head, *prev = nullptr;
    while (curr && val > curr->val) {
        prev = curr;
        curr = curr->next;
    }
    if (prev) prev->next = n;
    if (curr) curr->prev = n;
    n->next = curr;
    n->prev = prev;
    return prev ? head : n;
}
