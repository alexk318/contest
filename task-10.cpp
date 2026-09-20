/*
3871. Count Commas in Range II (Medium)
*/

class Solution {
public:
    long long countCommas(long long n) {
    
        long long result = 0;
        int s = std::floor((log(n) / log(1000)));  // log10(n)

        if ((n - std::pow(1000, s) + 1) < 0) { --s;  }

        if (s != 0) { result += s * (n - std::pow(1000, s) + 1); }

        for (size_t i = 1; i < s; ++i) {
            result += i * ((std::pow(1000, i + 1) - 1) - (std::pow(1000, i)) + 1);  
        }

        return result;

    }
};
