#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

// Boyer and Moore's Majority Vote Algorithm
// http://www.cs.utexas.edu/~moore/best-ideas/mjrty/example.html

// Make Sure a Majority Element Exists
bool IsMajority(const vector<int> &ivec, int majority) {
  int cnt = 0;
  for (const auto &val : ivec)
    if (val == majority) ++cnt;
  return cnt > ivec.size() / 2;
}
  
// Find the Majority Element If It Exists
int FindMajority(const vector<int> &ivec) {
  int cand, cnt = 0;
  for (const auto &val : ivec) {
    if (cnt == 0) cand = val;
    if (cand == val) ++cnt;
    else --cnt;
  }
  assert(IsMajority(ivec, cand));
  return cand;
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> ivec;
    int i;
    stringstream ss(line);
    while (ss >> i)
      ivec.push_back(i);
    cout << FindMajority(ivec) << endl;
  }
  return 0;
}
