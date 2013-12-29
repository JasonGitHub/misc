void Alloc(int* &arr, int &capacity) {
  int* new_arr = new int[capacity * 2];
  copy(arr, arr + capacity, new_arr);
  delete[] arr;
  arr = new_arr;
  capacity *= 2;
}

int FindPos(int* arr, int size, int val) {
  int lo = 0;
  int hi = size - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (val < arr[mid]) hi = mid - 1;
    else if (val > arr[mid]) lo = mid + 1;
    else return mid;
  }
  return lo; 
}

int* InsertSorted(int* &arr, int &capacity, int &size, int val) {
  if (size == capacity) Alloc(arr, capacity);
  int pos = FindPos(arr, size, val);
  ++size;
  for (int i = pos + 1; i < size; ++i) {
    swap(arr[pos], arr[i]);
  }
  arr[pos] = val;
  return arr + pos;
}
