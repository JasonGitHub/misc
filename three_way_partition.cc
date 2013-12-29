// consider the sorted array in three parts: bottom, middle, top
// the middle part is in range [low, high]
void threeWayPartition(int* data, int size, int low, int high) {
  int p = -1;  // end of bottom
  int q = size;  // start of top
  for (int i = 0; i < q;) {
    if (data[i] < low) {  // belongs to bottom
      swap(data[i], data[++p]);
      ++i;
    } else if (data[i] >= high) {  // belongs to top
      swap(data[i], data[--q]);
      // no need to increment i here, because an "unexamined" element is swaped to current place
    } else {  // just right
      ++i;
    }
  }
}
