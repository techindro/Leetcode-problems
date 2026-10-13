#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> squares(n);
        
        for (int i = 0; i < n; ++i) {
            squares[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        std::sort(squares.begin(), squares.end());
        
        long long max_sum = 0;
        int odd_count = n / 2;
        
        for (int i = 0; i < odd_count; ++i) {
            max_sum -= squares[i];
        }
        
        for (int i = odd_count; i < n; ++i) {
            max_sum += squares[i];
        }
        
        return max_sum;
    }
};
