/*
118. Pascal's Triangle
*/

#include <iostream>
#include <vector>

int main() {
	int num_rows = 5;

	std::vector<std::vector<int>> rows = { { 1 } };
	rows.reserve(30);

	std::vector<int> row = { 1 };
	row.reserve(30);

	for (size_t num = 1; num < num_rows; ++num) {

		for (size_t i = row.size() - 1; i > 0; --i) {
			row[i] = row[i] + row[i - 1];
		}

		row.push_back(1);
		rows.push_back(row);

	}

	return 0;
}
