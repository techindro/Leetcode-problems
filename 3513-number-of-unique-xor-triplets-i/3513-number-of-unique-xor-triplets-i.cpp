class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return n;
        }
        
        return 1 << (static_cast<int>(std::log2(n)) + 1);
    }
};
