class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open_count, int close_count, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open_count < n) {
            current.push_back('(');
            backtrack(result, current, open_count + 1, close_count, n);
            current.pop_back();
        }

        if (close_count < open_count) {
            current.push_back(')');
            backtrack(result, current, open_count, close_count + 1, n);
            current.pop_back();
        }
    }
};
