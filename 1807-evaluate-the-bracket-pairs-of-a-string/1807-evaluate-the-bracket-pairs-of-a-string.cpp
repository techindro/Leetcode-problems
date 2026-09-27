class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
        std::unordered_map<std::string, std::string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        std::string result = "";
        std::string current_key = "";
        bool inside_bracket = false;
        
        for (char c : s) {
            if (c == '(') {
                inside_bracket = true;
            } else if (c == ')') {
                inside_bracket = false;
                auto it = dict.find(current_key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                current_key = "";
            } else {
                if (inside_bracket) {
                    current_key += c;
                } else {
                    result += c;
                }
            }
        }
        
        return result;
    }
};
