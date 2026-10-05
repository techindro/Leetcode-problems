class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); 
        
        for (char c : s) {
            if (c == '(') {
                st.push(0); 
            } else {
                int inner_score = st.top();
                st.pop();

                int current_score = max(2 * inner_score, 1);
                
                st.top() += current_score;
            }
        }
        
        return st.top();
    }
};
