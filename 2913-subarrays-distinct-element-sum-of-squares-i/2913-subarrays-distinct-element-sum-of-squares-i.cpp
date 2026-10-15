class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            std::vector<bool> seen(101, false); 
            int distinctCount = 0;
            
            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinctCount++;
                }
                totalSum += distinctCount * distinctCount;
            }
        }
        
        return totalSum;
    }
};
