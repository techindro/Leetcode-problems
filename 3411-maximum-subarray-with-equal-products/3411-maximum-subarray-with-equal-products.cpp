class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        long long total_lcm = 1;
        int max_val = 0;
        for (int x : nums) {
            total_lcm = lcm(total_lcm, (long long)x);
            max_val = max(max_val, x);
        }
        long long max_prod = total_lcm * max_val;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;
            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                if (prod > max_prod) {
                    break;
                }
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
