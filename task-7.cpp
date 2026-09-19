/*
414. Third Maximum Number
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // При сортировке вектора по убыванию нам уже как бы известен ответ, но
        // мешает только то, что элементы могу повторяться

        int counter = 1; // Если в векторе есть число, то оно уже о
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        
        for (size_t i = 0; i < nums.size(); ++i) {
            if (counter == 3) {
                return nums[i];
            }

            if (i + 1 != nums.size() && nums[i] != nums[i + 1]) {
                ++counter;
            }
        }
        return nums[0];

    }
};
