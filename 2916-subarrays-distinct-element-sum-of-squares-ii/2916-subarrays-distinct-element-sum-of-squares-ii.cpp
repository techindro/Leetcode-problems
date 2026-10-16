class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<long long> tree_sum;
    vector<long long> tree_sq_sum;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            long long v = lazy[node];
            int mid = start + (end - start) / 2;

            int left = 2 * node;
            tree_sq_sum[left] = (tree_sq_sum[left] + 2 * v * tree_sum[left] % MOD + v * v % MOD * (mid - start + 1) % MOD) % MOD;
            tree_sum[left] = (tree_sum[left] + v * (mid - start + 1)) % MOD;
            lazy[left] = (lazy[left] + v) % MOD;

            int right = 2 * node + 1;
            tree_sq_sum[right] = (tree_sq_sum[right] + 2 * v * tree_sum[right] % MOD + v * v % MOD * (end - mid) % MOD) % MOD;
            tree_sum[right] = (tree_sum[right] + v * (end - mid)) % MOD;
            lazy[right] = (lazy[right] + v) % MOD;

            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start and end <= r) {
            tree_sq_sum[node] = (tree_sq_sum[node] + 2 * val * tree_sum[node] % MOD + val * val % MOD * (end - start + 1) % MOD) % MOD;
            tree_sum[node] = (tree_sum[node] + val * (end - start + 1)) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq_sum[node] = (tree_sq_sum[2 * node] + tree_sq_sum[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_sq_sum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_seen;
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            int l = (last_seen.count(nums[r]) ? last_seen[nums[r]] : -1) + 1;
            update(1, 0, n - 1, l, r, 1);
            last_seen[nums[r]] = r;
            ans = (ans + tree_sq_sum[1]) % MOD;
        }

        return ans;
    }
};
