void ReverseString(char* str, int len) {
	int i = 0, j = len - 1;
	char tmp;
	while (i < j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		++i;
		--j;
	}
}

void ReverseWords(char* str, int len) {
	char* cur = str;
	char* start;
	int wordlen;
	ReverseString(str, len);
	
	while (*cur != '\0') {
		while (*cur == ' ') {
			++cur;
		}
		start = cur;
		while (*cur != ' ' && *cur != '\0') {
			++cur;
		}
		wordlen = cur - start;
		ReverseString(start, wordlen);
	}
}

// A Simple Solution (using stl function "reverse")
void Reverse(string &s) {
  reverse(s.begin(), s.end());
  string::iterator prev = s.begin(), iter;
  while (true) {
    iter = find(prev, s.end(), ' '); 
    reverse(prev, iter);
    if (iter == s.end()) break;
    while (iter != s.end() && *iter == ' ') ++iter;
    prev = iter;
  }
}
