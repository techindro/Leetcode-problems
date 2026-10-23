class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int zero_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero_idx = i;
                break;
            }
        }

        auto is_valid_cycle = [&](int step) {
            for (int i = 1; i < n; ++i) {
                int prev_pos = (zero_idx + (i - 1) * step + n) % n;
                int curr_pos = (zero_idx + i * step + n) % n;
                if (nums[prev_pos] > nums[curr_pos]) {
                    return false;
                }
            }
            return true;
        };

        int min_ops = 1e9;

        if (is_valid_cycle(1)) {
            min_ops = std::min(min_ops, zero_idx);
            min_ops = std::min(min_ops, (n - zero_idx) + 2);
        }

        if (is_valid_cycle(-1)) {
            min_ops = std::min(min_ops, zero_idx + 2);
            min_ops = std::min(min_ops, n - zero_idx);
        }

        return min_ops == 1e9 ? -1 : min_ops;
    }
};
