class Solution {
private:
    set<string> parse(const string& s, int& i) {
        vector<set<string>> groups;
        set<string> current_concat = {""};

        while (i < s.length() && s[i] != '}') {
            if (s[i] == ',') {
                groups.push_back(current_concat);
                current_concat = {""};
                i++;
            } else if (s[i] == '{') {
                i++; 
                set<string> next_set = parse(s, i);
                i++; 

                set<string> multiplied;
                for (const string& s1 : current_concat) {
                    for (const string& s2 : next_set) {
                        multiplied.insert(s1 + s2);
                    }
                }
                current_concat = multiplied;
            } else {
                string word = "";
                while (i < s.length() && isalpha(s[i])) {
                    word += s[i];
                    i++;
                }

                set<string> multiplied;
                for (const string& s1 : current_concat) {
                    multiplied.insert(s1 + word);
                }
                current_concat = multiplied;
            }
        }

        groups.push_back(current_concat);
        set<string> result;
        for (const auto& group : groups) {
            result.insert(group.begin(), group.end());
        }
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> final_set = parse(expression, i);
        return vector<string>(final_set.begin(), final_set.end());
    }
};
