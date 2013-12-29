int GetSize(Node* n) {
    int cnt = 0;
    while (n) {
        n = n->next;
        ++cnt;
    }
    return cnt;
}
Node* FindMergeNode(Node *a, Node *b) {
    int diff = GetSize(a) - GetSize(b);
    Node** x = diff > 0 ? &a : &b;
    for (int i = 0; i < abs(diff); ++i) {
        *x = (*x)->next;
        x = &((*x)->next);
    }
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}
