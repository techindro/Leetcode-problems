class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n == 0) return 0;
        vector<long long> dp(n + 1, 2147483647);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                if (i - j >= 0) {
                    long long current_cost = dp[i - j] + costs[i - 1] + (long long)j * j;
                    if (current_cost < dp[i]) {
                        dp[i] = current_cost;
                    }
                }
            }
        }
        return dp[n];
    }
};
