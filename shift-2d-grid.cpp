/*
1260. Shift 2D Grid
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
        first_column.reserve(grid[0].size());

        for (size_t row = 0; row < grid.size(); ++row) {
            first_column.push_back(grid[row][0]);
        }

        for (size_t _ = 0; _ < k; ++_) {

            for (std::vector<int>& row : grid) {
                this->shift_right(row);
            }

            for (size_t row = 0; row < grid.size(); ++row) {
                first_column[row] = grid[row][0];
            }

            this->shift_right(first_column);

            for (size_t i = 0; i < first_column.size(); ++i) {
                grid[i][0] = first_column[i];
            }
        }
        
        return grid;
    }
};
