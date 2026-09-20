/*
1260. Shift 2D Grid

Для удобства введем функцию shift_right(std::vector<int>& vec), осуществляющую перестановку всех элементо вправо.
Последний элемент становится первым.

Матрица реализуется вектором строк, что удобно для перемещения первых двух столбцов влево (Просто применив (shift_right)),
но неудобно для изменения порядка элемнтов в последнем столбце. Поэтому создается отдельный вектор, где элементы столбца расположеные горизонтально.
*/

class Solution {
public:

    void shift_right(std::vector<int>& vec) {
        int last_element = vec[vec.size() - 1];

        for (size_t i = vec.size() - 1; i > 0; --i) {
            vec[i] = vec[i - 1];
        }
         vec[0] = last_element;
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        std::vector<int> first_column = {};
        first_column.reserve(grid[0].size());    // Для эффективности сразу займем память для вектора

        for (size_t _ = 0; _ < k; ++_) {    // Выполняем k итераций

            for (std::vector<int>& row : grid) {
                this->shift_right(row);
            }

            for (size_t row = 0; row < grid.size(); ++row) {
                first_column.push_back(grid[row][0]);
            }

            this->shift_right(first_column);    // Спускаем в столбце элементы вниз

            for (size_t i = 0; i < first_column.size(); ++i) {
                grid[i][0] = first_column[i];   // Заменяем первый столбец в исходной матрице
            }

            first_column.clear();
        }
        
        return grid;
    }
};
