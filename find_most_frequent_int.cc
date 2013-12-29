int FindFreqInt(vector<int> a) {
	map<int,int> m;
	for (int i = 0; i < a.size(); ++i) {
		++m[a[i]];
	}
	map<int,int>::iterator it;
	int max = 0;
	int max_key;
	for (it = m.begin(); it != m.end(); ++it) {
		if (it->second > max) {
			max = it->second;
			max_key = it->first;
		}
	}
	return max_key;
}
