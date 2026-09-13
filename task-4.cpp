/*
3903. Smallest Stable Index I
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int current_min_index = -1;

        for (size_t i = 0; i < nums.size(); ++i) {
	        std::span<int> left = std::span<int>(nums).subspan(0, i + 1);
	        auto left_max = *std::max_element(left.begin(), left.end());

	        std::span<int> right = std::span<int>(nums).subspan(i, nums.size() - i);
	        auto right_min = *std::min_element(right.begin(), right.end());

            if (left_max - right_min <= k && i < current_min_index) {
                current_min_index = i;
            }
        }

        return current_min_index;
        
    }
};
