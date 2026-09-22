class Solution {
private:
    struct Node {
        int total_prod;
        int cnt[6];
        Node() {
            total_prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.total_prod = (left.total_prod * right.total_prod) % k;
        
        for (int i = 0; i < k; ++i) {
            parent.cnt[i] += left.cnt[i];
        }
        for (int i = 0; i < k; ++i) {
            int next_rem = (left.total_prod * i) % k;
            parent.cnt[next_rem] += right.cnt[i];
        }
        return parent;
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int val = nums[start] % k;
            tree[node].total_prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k;
            memset(tree[node].cnt, 0, sizeof(tree[node].cnt));
            tree[node].total_prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) return query(2 * node, start, mid, l, r);
        if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);
        
        Node left_res = query(2 * node, start, mid, l, r);
        Node right_res = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left_res, right_res);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k_val, vector<vector<int>>& queries) {
        n = nums.size();
        k = k_val;
        tree.assign(4 * n, Node());
        build(nums, 1, 0, n - 1);

        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            
            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            result.push_back(res.cnt[x]);
        }
        
        return result;
    }
};
