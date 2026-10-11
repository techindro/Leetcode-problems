class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int index_1_based = i + 1; 
            if (n % index_1_based == 0) {
                total_sum += nums[i] * nums[i];
            }
        }
        
        return total_sum;
    }
};
