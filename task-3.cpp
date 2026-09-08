/*
3870. Count Commas in Range
*/

#include <cmath>

class Solution {
public:
    int countCommas(int n) {
        int result = 0;
        int s = std::floor(log(n) / log(1000));

        if (s != 0) { result += n - (std::pow(1000, s) - 1); }

        for (size_t i = 1; i < s; ++i) {
            result += (std::pow(1000, i + 1) - 1) - std::pow(1000, i);
        }

        return result;
    }
};
