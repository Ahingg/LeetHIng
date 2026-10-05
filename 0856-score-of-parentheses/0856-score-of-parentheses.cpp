class Solution {
public:
    int scoreOfParentheses(string s) {
        int len = s.length();
        stack<int> st;
        stack<pair<int, int>> nums;
        // while the open is not 0 after evaluation, then its not closed yet.
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(st.top() == i - 1) {
                    nums.push({st.top(), 1});
                }
                else {
                    int total = 0;
                    // cout << nums.top().first << " " << st.top() << endl;
                    while(!nums.empty() && !st.empty() && ((nums.top().first) >= st.top())) {
                        cout << nums.top().second << endl;
                        total += nums.top().second;
                        nums.pop();
                    }
                    nums.push({st.top(), total * 2});
                }
                st.pop();
            }


        }

        int res = 0;
        while(!nums.empty()) {
            res += nums.top().second;
            nums.pop();
        }
        return res;
    }
};