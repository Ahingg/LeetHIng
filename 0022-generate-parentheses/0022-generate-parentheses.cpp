class Solution {
public:

    // dfsin aja
    void resolve(int front, int back, string s, vector<string>& res) {
        if(front == 0 && back == 0) {
            res.push_back(s);
            return;
        }

        if(front > 0) {
            resolve(front-1, back, s + '(', res);
        }
        if(back > front) resolve(front, back-1, s+')', res
        );
    }
    // vector<vector<string>> db = {
    //     {"()"},
    //     {"(())", "()()"}
    // }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        resolve(n, n, "", res);
        // for(const auto& s: res) cout << s << endl;
        return res;
    }
};