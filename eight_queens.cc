#include <iostream>
#include <vector>

using namespace std;

class Grid {
private:
	int num_of_col_;
	int num_of_row_;
	vector<vector<bool> > grid_;
public:
	Grid(int row, int col):num_of_row_(row), num_of_col_(col) {
		for (int i = 0; i < row; ++i) {
			vector<bool> tmp(col, false);
			grid_.push_back(tmp);
		}
	}
	inline int num_of_col() const {
		return num_of_col_;
	}
	inline int num_of_row() const {
		return num_of_row_;
	}	
	void set(int row, int col, bool value) {
		grid_[row][col] = value;
	}
	bool get(int row, int col) const {
		return grid_[row][col];
	}
	void print() const {
		for (int i = 0; i < num_of_row_; ++i) {
			for (int j = 0; j < num_of_col_; ++j) {
				cout << grid_[i][j] << " ";
			}
			cout << endl;
		}
	}
};

bool IsSafe(int row, int col, const Grid &map) {
	//check left
	for (int i = 0; i < col; ++i) {
		if (map.get(row, i)) return false;
	}
	//check upper-left
	for (int i = row - 1, j = 1; i >= 0 && col - j >= 0; --i) {
		if (map.get(i, col - j)) return false;
		++j;
	}
	//check lower-left
	for (int i = row + 1, j = 1; i < map.num_of_row() && col - j >= 0; ++i) {
		if (map.get(i, col - j)) return false;
		++j;
	}
	return true;
}

void PlaceQueen(int row, int col, Grid &map) {
	map.set(row, col, true);
}

void RemoveQueen(int row, int col, Grid &map) {
	map.set(row, col, false);
}

bool Solve(Grid &map, int col) {
	if (col >= map.num_of_col()) return true;
	for (int row = 0; row < map.num_of_row(); ++row) {
		if (IsSafe(row, col, map)) {
			PlaceQueen(row, col, map);
			if (Solve(map, col + 1)) return true;
			RemoveQueen(row, col, map);
		}
	}
	return false;
}

int main() {
	Grid map(8, 8);
	Solve(map, 0);
	map.print();
	return 0;
}
