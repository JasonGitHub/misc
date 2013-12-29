#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::endl;

string Encode(string str) {
  string ret;
  int cnt = 0;
  for (string::iterator it = str.begin(); it != str.end(); ++it) {
    ++cnt;
    if (it + 1 == str.end() || *it != *(it + 1)) {
      ret += *it + to_string(cnt);
      cnt = 0;
    }
  }
  return ret;
}

int main() {
  string str;
  while (cin >> str) {
    cout << Encode(str) << endl;
  }
  return 0;
}
