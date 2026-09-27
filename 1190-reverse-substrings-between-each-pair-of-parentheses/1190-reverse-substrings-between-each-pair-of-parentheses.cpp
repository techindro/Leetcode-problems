class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opened;
        string result;
        
        for (char c : s) {
            if (c == '(') {
                opened.push_back(result.length());
            } else if (c == ')') {
                int start = opened.back();
                opened.pop_back();
                reverse(result.begin() + start, result.end());
            } else {
                result.push_back(c);
            }
        }
        
        return result;
    }
};
