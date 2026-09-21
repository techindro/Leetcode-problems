class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> dp(k, 0);
        
        for (int x : nums) {
            std::vector<long long> next_dp(k, 0);
            int rem = x % k;
            
            next_dp[rem]++;
            
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * rem) % k] += dp[r];
                }
            }
            
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }
            
            dp = std::move(next_dp);
        }
        
        return ans;
    }
};
