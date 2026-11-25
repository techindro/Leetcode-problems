class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
        const long long BASE1 = 1315423911LL, BASE2 = 2654435761LL;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            long long val = nums[i] + 1000000007LL; // Handle negative/zero values safely
            h1[i + 1] = (h1[i] * BASE1 + (val % MOD1)) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + (val % MOD2)) % MOD2;
        }

        auto check = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);

            for (int i = 0; i + len <= n; ++i) {
                long long x1 = (h1[i + len] - (h1[i] * p1[len]) % MOD1 + MOD1) % MOD1;
                long long x2 = (h2[i + len] - (h2[i] * p2[len]) % MOD2 + MOD2) % MOD2;
                uint64_t combined = (static_cast<uint64_t>(x1) << 32) | static_cast<uint64_t>(x2);
                freq[combined]++;
            }

            for (const auto& [hashVal, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
