class Solution {
private:
    int n;
    int timer;
    vector<vector<int>> adj;
    vector<int> in, out;
    vector<vector<int>> up;
    int LOG;
    vector<int> bit;

    void updateBIT(int idx, int val) {
        for (; idx <= 2 * n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int queryBIT(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum ^= bit[idx];
        }
        return sum;
    }

    void rangeXOR(int l, int r, int val) {
        updateBIT(l, val);
        updateBIT(r + 1, val);
    }

    void dfs(int node, int p, const string& s) {
        in[node] = ++timer;
        up[node][0] = p;
        for (int i = 1; i < LOG; ++i) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        for (int nbr : adj[node]) {
            if (nbr != p) {
                dfs(nbr, node, s);
            }
        }
        out[node] = ++timer;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }

    int getLCA(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;
        for (int i = LOG - 1; i >= 0; --i) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        string suneravilo = s;
        this->n = n;
        this->timer = 0;
        this->LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        in.resize(n);
        out.resize(n);
        up.assign(n, vector<int>(LOG));
        bit.assign(2 * n + 2, 0);

        dfs(0, 0, s);

        for(int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            rangeXOR(in[i], out[i], mask);
        }

        vector<bool> ans;
        for (const string& qStr : queries) {
            stringstream ss(qStr);
            string type;
            ss >> type;
            if (type == "update") {
                int node;
                char newChar;
                ss >> node >> newChar;
                int oldMask = 1 << (s[node] - 'a');
                int newMask = 1 << (newChar - 'a');
                
                rangeXOR(in[node], out[node], oldMask ^ newMask);
                s[node] = newChar;
            } 
            else {
                int u, v;
                ss >> u >> v;
                int lca = getLCA(u, v);

                int maskU = queryBIT(in[u]);
                int maskV = queryBIT(in[v]);
                int maskLCA = 1 << (s[lca] - 'a');

                int pathMask = maskU ^ maskV ^ maskLCA;

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }
        return ans;
    }
};