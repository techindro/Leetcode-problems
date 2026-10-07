class Solution {
private:
    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int level_size = q.size();
            
            for (int i = 0; i < level_size; ++i) {
                std::string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    std::string next_state = curr.substr(0, j) + curr.substr(j + 1);

                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push(next_state);
                    }
                }
            }

            if (found) return result;
        }

        if (result.empty()) return {""};
        return result;
    }
};
