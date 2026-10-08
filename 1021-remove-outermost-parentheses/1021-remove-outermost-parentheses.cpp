class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string ans = "";
        int opened = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    ans += c;
                }
                opened++;
            } else {
                opened--;
                if (opened > 0) {
                    ans += c;
                }
            }
        }
        
        return ans;
    }
};
