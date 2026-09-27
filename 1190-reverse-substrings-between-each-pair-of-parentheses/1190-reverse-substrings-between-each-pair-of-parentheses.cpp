class Solution {
public:
    int i = 0;
    string solve(const string& s) {
        string curr = "";
        while(i < s.length()) {
            if(s[i] == '(') {
                i++;
                curr += solve(s);
            }
            else if(s[i] == ')') {
                i++;
                reverse(curr.begin(), curr.end());
                return curr;
            }
            else {
                curr += s[i];
                i++;
            }
        }
        return curr;
    }
    string reverseParentheses(string s) {
        return solve(s);
    }
};