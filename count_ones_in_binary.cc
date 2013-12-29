// Count number of 1's in binary representation
int CountOnes(int n) {
  int cnt = 0;
  while (n) {
    n &= n - 1;
    ++cnt;
  }
  return cnt;
}
