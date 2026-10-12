class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        std::vector<int> bitCount(31, 0);
        
        for (int num : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSumOfSquares = 0;
        
        for (int i = 0; i < k; ++i) {
            long long currentNum = 0;
            for (int j = 0; j < 31; ++j) {
                if (bitCount[j] > 0) {
                    currentNum |= (1LL << j);
                    bitCount[j]--;
                }
            }
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSumOfSquares;
    }
};