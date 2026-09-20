/*
118. Pascal's Triangle

Каждый элемент треугольника равен сумме двух соседних элементов, стоящих в верхнем ряду. Каждый ряд заканчивается единицей.
*/

#include <iostream>
#include <vector>

int main() {
	std::vector<std::vector<int>> rows = { { 1 } };
	rows.reserve(30);    // 30 - Максимальное число рядов по условию задачи

	std::vector<int> row = { 1 };
	row.reserve(30);

	for (size_t num = 1; num < numRows; ++num) {

		for (size_t i = row.size() - 1; i > 0; --i) {
			row[i] = row[i] + row[i - 1];    // Элемент в следующем ряду равен сумме двух соседних элементов в прошлом ряду
		}

		row.push_back(1);    // Т. к. при каждой итерации последняя единица заменяется, то для каждого ряда добавляем новую
		rows.push_back(row);

	}

	return rows;
}
