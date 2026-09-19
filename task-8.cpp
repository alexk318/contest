/*
137. Single Number II (Medium)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        size_t i = 2;

        while(i < nums.size()) {
            // Нужно определять, идут ли три числа вместе как группа одинаковых чисел

            if (nums[i] != nums[i-1] || nums[i] != nums[i-2]) {

                if (nums[i] != nums[i-1]) {
                    if (nums[i] == nums[i-2]) { return nums[i-1]; }
                    else {return nums[i]; }
                }

                else {

                    if (nums[i] == nums[i-1]) { return nums[i-2]; }
                    else {return nums[i]; }

                }
            }

            i += 3;

        }
        return nums[nums.size() - 1];
    }
};
