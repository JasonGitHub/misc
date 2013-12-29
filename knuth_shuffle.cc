int UniformRand(int n) {
	int top = (RAND_MAX - n + 1) / n * n + n - 1;
	int r = rand();
	while (r > top) {
		r = rand();
	}
	return r % n;
}

template <typename T>
void Shuffle(vector<T> &v) {
	for (int i = v.size() - 1; i > 0; --i) {
		int key = UniformRand(i);
		swap(v[i], v[key]);
	}
}
