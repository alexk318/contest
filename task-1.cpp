// 35. Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = -1;
        int r = nums.size();
        int m = 0;

        while (l < r - 1) {
            m = (l + r) / 2;

            if (nums[m] < target) { l = m; }
            else { r = m; }
        }

        return r;
    }
};
