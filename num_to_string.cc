string NumToString(int i) {
	string s;
	while (i / 10 != 0) {
		s = char(i % 10 + '0') + s;
		i = i / 10;
	}
	s = char(i % 10 + '0') + s;
	return s;
}
