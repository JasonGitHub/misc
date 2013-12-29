int abs(int i) {
	return (i ^ (i >> 31)) + (i >> 31 & 1);
}
