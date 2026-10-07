class Solution {
public:

    void resolve(string s, vector<string>& ans, int i, int j, vector<char> p) {
        int count = 0;
        for(int k = i; k < s.size(); k++) {
            if(s[k] == p[0]) count++;
            if(s[k] == p[1]) count--;
            if(count < 0) {
                for(int x = j; x <= k; x++) {
                    if(s[x] == p[1] && (x == j || s[x-1] != p[1])) {
                        resolve(s.substr(0, x) + s.substr(x+1), ans, k, x, p);
                    }
                }
                return ;
            }
        }

        string rev(s.rbegin(), s.rend());

        if(p[0] == '(') resolve(rev, ans, 0, 0, {')', '('});
        else ans.push_back(rev);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        resolve(s, ans, 0, 0, {'(', ')'});
        return ans;
    }
};