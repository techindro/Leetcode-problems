class Solution {
public:
    int longestValidParentheses(std::string s) {
        int left = 0, right = 0, max_len = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) {
                max_len = std::max(max_len, left + right);
            } else if (right > left) {

                left = right = 0;
            }
        }

        left = right = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) {
                max_len = std::max(max_len, left + right);
            } else if (left > right) {
                
                left = right = 0;
            }
        }
        
        return max_len;
    }
};
