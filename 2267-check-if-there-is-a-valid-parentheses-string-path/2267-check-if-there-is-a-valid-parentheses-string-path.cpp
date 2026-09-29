class Solution {
    int m, n;
    int dp[100][100][201];
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {
        if (i >= m || j >= n) return false;
        
        balance += (grid[i][j] == '(') ? 1 : -1;
        
        if (balance < 0) return false;
        if (balance > (m - 1 - i) + (n - 1 - j)) return false;
        
        if (i == m - 1 && j == n - 1) return balance == 0;
        
        if (dp[i][j][balance] != -1) return dp[i][j][balance];
        
        bool ans = dfs(grid, i + 1, j, balance) || dfs(grid, i, j + 1, balance);
        dp[i][j][balance] = ans;
        return ans;
    }
    
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, 0);
    }
};