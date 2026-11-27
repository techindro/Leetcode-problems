class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freeCount(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int firstCopyGain = 1 + freeCount[i];

            if (price > budget) continue;

            for (int b = budget; b >= price; --b) {
                if (dp[b - price] != -1) {
                    dp[b] = max(dp[b], dp[b - price] + firstCopyGain);
                }
            }

            for (int b = 2 * price; b <= budget; ++b) {
                if (dp[b - price] != -1) {
                    dp[b] = max(dp[b], dp[b - price] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
