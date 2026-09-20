/*
137. Single Number II (Medium)

По условию задачи мы точно знаем что чисел, не равных искомому числу ровно по три штуки.
В таком случае в отсортированном списке можно рассматривать по группы три числа. Если в данной
группе мы найдем число, отличное от других, то это число - искомое.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        size_t i = 2;

        while(i < nums.size()) {
            if (nums[i] != nums[i-1] || nums[i] != nums[i-2]) {   // Если в группе имеется одно число, не равно двум другим,
                
                if (nums[i] != nums[i-1]) {    // Если третье число не равно второму, 
                    if (nums[i] == nums[i-2]) { return nums[i-1]; } // Но третье число равно первому, то искомое число - второе
                    else { return nums[i]; }
                }
                else if (nums[i] == nums[i-1]) {
                    return nums[i-2];
                } 
                else { return nums[i]; }
            }
            i += 3; // Ищем в следующей тройке
        }
        return nums[nums.size() - 1]; // Если не нашли не в одной тройке, то это означает что искомое число - последнее
    }
};
