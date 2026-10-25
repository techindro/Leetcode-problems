class Solution {
private:
    int m, n;

    void dfs(int r, int c, std::vector<std::vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1) {
            return;
        }
        
        grid[r][c] = 1;
        
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                    if (grid[r][c] == 0) {
                        dfs(r, c, grid);
                    }
                }
            }
        }
        
        int closedIslandsCount = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    dfs(r, c, grid);
                    closedIslandsCount++;
                }
            }
        }
        
        return closedIslandsCount;
    }
};
