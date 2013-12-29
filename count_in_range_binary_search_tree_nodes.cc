int CountNode(TreeNode* n, int lo, int hi) {
  if (n == NULL) return 0;
  if (n->val < lo) return CountNode(n->right, lo, hi);
  if (n->val > hi) return CountNode(n->left, lo, hi);
  return 1 + CountNode(n->left, lo, hi) + CountNode(n->right, lo, hi);
}
