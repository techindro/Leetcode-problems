class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> bracket_map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        std::stack<char> st;
        
        for (char ch : s) {
            if (bracket_map.count(ch)) {
                if (st.empty() || st.top() != bracket_map[ch]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }
        
        return st.empty();
    }
};
