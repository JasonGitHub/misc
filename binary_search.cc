// Iterative
int BinarySearch(int *arr, int val, int size) {
  int lo = 0, hi = size - 1; 
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (val < arr[mid]) hi = mid - 1;
    else if (val > arr[mid]) lo = mid + 1;
    else return mid;
  }
  return -1;
}

// Recursive
int BinarySearch(int *arr, int val, int lo, int hi) {
  if (lo > hi) return -1; 
  int mid = lo + (hi - lo) / 2;
  if (val == arr[mid]) return mid;
  else if (val < arr[mid]) BinarySearch(arr, val, lo, mid - 1);
  else BinarySearch(arr, val, mid + 1, hi);
}

void Reallocate(int *&arr, size_t new_capacity) {
  int *new_arr = new int[new_capacity];
  for (size_t i = 0; i < new_capacity / 2; ++i) {
    new_arr[i] = arr[i];
  } 
  delete[] arr;
  arr = new_arr;
}
