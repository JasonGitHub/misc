void max(int* arr, int n, int k) {
  stack<int> st;
  int max = INT_MIN;
  for (size_t i = 0; i < k; ++i) {
    if (arr[i] >= max) {
      max = arr[i];
      st.push(arr[i]);
    }
  }
  cout << st.top();
  for (size_t i = k; i < n; ++i) {
    if (st.top() == arr[i - k]) st.pop();
    if (arr[i] > st.top()) st.push(arr[i]);
    cout << st.top();
  }
}
