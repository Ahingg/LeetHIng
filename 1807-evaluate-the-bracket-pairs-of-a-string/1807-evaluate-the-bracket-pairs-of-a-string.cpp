class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for(const auto& v: knowledge) dict[v[0]] = v[1];

        int len = s.length();

        string result = "";
        int i = 0;
        while(i < len) {
            if(s[i] == '(') {
                i++;
                string temp = "";
                while(s[i] != ')') {
                    temp += s[i];
                    i++;
                }
                if(dict.find(temp) != dict.end()) result += dict[temp];
                else result += '?';
            }
            else {
                result += s[i];
            }

            i++;
        }

        return result;
    }
};