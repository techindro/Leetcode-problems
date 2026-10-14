#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        int globalMin = INT_MAX;
        bool hasOdd = false;

        for (int num : nums1) {
            if (num < globalMin) {
                globalMin = num;
            }
            if (num % 2 != 0) {
                hasOdd = true;
            }
        }

        if (globalMin % 2 != 0) {
            return true;
        }

        return !hasOdd;
    }
};
