class Solution {
public:
    string processStr(string s) {
        int len = s.length();
        string result = "";
        for(int i = 0; i < len; i++){
            if(s[i] >= 'a' && s[i] <= 'z') result += s[i];
            else if(s[i] == '*' && result != "") result.pop_back();
            else if(s[i] == '#') result += result;
            else if(s[i] == '%') reverse(result.begin(), result.end());
        }
        return result;
    }
};