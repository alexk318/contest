/*
136. Single Number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        nums.push_back(nums.back() + 1);

        for (size_t i = 1; i < nums.size(); i += 2) {
            if (nums[i] != nums[i-1]) {
                return nums[i-1];
            }
        }
        return -1;
    }
};
