class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> st;
        // to handle the problem where string starts with )
        st.push(-1);
        int ans = 0;

        for(int i = 0; i < len; i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};