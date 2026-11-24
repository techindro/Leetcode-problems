class Solution {
private:
    vector<int> memo;
    int maxInt;

    bool canWin(int mask, int remaining) {
        if (memo[mask] != 0) {
            return memo[mask] == 1;
        }

        for (int i = 0; i < maxInt; ++i) {
            if ((mask & (1 << i)) == 0) {
                int num = i + 1;
                if (num >= remaining || !canWin(mask | (1 << i), remaining - num)) {
                    memo[mask] = 1;
                    return true;
                }
            }
        }

        memo[mask] = -1;
        return false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;

        int totalSum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (totalSum < desiredTotal) return false;

        maxInt = maxChoosableInteger;
        memo.assign(1 << maxChoosableInteger, 0);

        return canWin(0, desiredTotal);
    }
};
