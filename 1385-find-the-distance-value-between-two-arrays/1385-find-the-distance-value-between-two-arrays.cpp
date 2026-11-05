class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        for (const int x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            if (it == arr2.end() || *it > x + d) {
                ++ans;
            }
        }
        return ans;
    }
};
