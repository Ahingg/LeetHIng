class Solution {
public:
    string removeOuterParentheses(string s) {
        int len = s.length();
        string ans = "";
        int balance = 0, i = 0;

        while(i < len) {
            // cout << s[i] << " " << balance << endl;
            if(s[i] == '(') {
                balance++;
                if(balance != 1) ans += s[i];
                
            }
            else {
                balance--;
                if(balance != 0) ans += s[i];
            }

            i++;
        }
        return ans;
    }
};