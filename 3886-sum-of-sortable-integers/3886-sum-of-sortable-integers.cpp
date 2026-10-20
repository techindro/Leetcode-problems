class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        auto check = [&](int k) {
            vector<int> rotatedMax(n / k);
            vector<int> rotatedMin(n / k);
            int blockIdx = 0;

            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int minVal = INT_MAX, maxVal = INT_MIN;
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k];
                    if (curr > next) {
                        drops++;
                    }
                    minVal = min(minVal, curr);
                    maxVal = max(maxVal, curr);
                }
                if (drops > 1) return false;
                
                rotatedMin[blockIdx] = minVal;
                rotatedMax[blockIdx] = maxVal;
                blockIdx++;
            }

            for (int i = 0; i < (n / k) - 1; ++i) {
                if (rotatedMax[i] > rotatedMin[i + 1]) {
                    return false;
                }
            }
            return true;
        };

        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (check(k)) {
                    totalSum += k;
                }
            }
        }

        return totalSum;
    }
};
