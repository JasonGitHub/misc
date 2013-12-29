// Given an array, find the k minimum elements a[0] - a[k - 1]

// Time: O(n) Space: O(1)
int* GetMinK(int* a, int* start, int* end, int k) {
  int* boundary = std::stable_partition(start, end, bind2nd(less<int>(), *start));
  int length = boundary - start + 1;
  if (length == k) return boundary;
  else if (k < length) return GetMinK(a, start, boundary, k);
  else return GetMinK(a, boundary + 1, end, k - length);
}

// Time: O(n) Space: O(1)
int* GetMinK(int* a, int size, int k) {
  std::make_heap(a, a + k);
  for (int i = k; i < size; ++i) {
    if (a[i] < a[0]) {
      pop_heap(a, a + k);
      swap(a[i], a[k - 1]);
      push_heap(a, a + k);
    }
  }
  return a + k - 1;
}
