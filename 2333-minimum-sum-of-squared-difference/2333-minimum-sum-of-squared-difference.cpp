class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        long long total_k = (long long)k1 + k2;
        int n = nums1.size();
        
        std::vector<int> diffs(n);
        int max_diff = 0;
        long long sum_diffs = 0;
        
        for (int i = 0; i < n; ++i) {
            diffs[i] = std::abs(nums1[i] - nums2[i]);
            max_diff = std::max(max_diff, diffs[i]);
            sum_diffs += diffs[i];
        }
        
        if (sum_diffs <= total_k) {
            return 0;
        }
        
        std::vector<long long> bucket(max_diff + 1, 0);
        for (int d : diffs) {
            bucket[d]++;
        }
        
        for (int d = max_diff; d > 0; --d) {
            if (bucket[d] == 0) {
                continue;
            }
            
            long long take = std::min(bucket[d], total_k);
            bucket[d] -= take;
            bucket[d - 1] += take;
            total_k -= take;
            
            if (total_k == 0) {
                break;
            }
        }
        
        long long ans = 0;
        for (int d = 1; d <= max_diff; ++d) {
            if (bucket[d] > 0) {
                ans += bucket[d] * ((long long)d * d);
            }
        }
        
        return ans;
    }
};
