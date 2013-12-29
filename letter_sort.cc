// letters = {a, b, c}, m = 3
// O(n * m)
void sort(char* arr) {
  size_t len = strlen(arr);
  char* p1 = arr;
  char* p2 = arr + len - 1;
  for (char c = 'a'; c < 'c'; ++c) {
    while (true) {
      while (*p1 == c) ++p1;
      while (*p2 != c) --p2;
      if (p1 > p2) break;
      swap(*p1, *p2);
    }
    p2 = arr + len - 1;
  }
}
