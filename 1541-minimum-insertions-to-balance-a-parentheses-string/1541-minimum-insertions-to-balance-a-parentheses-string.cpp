class Solution {
public:
    int minInsertions(string s) {
        // how if the case is ()(
        // bascially just change the balance to 2, or change )) to 1
        int len = s.length();
        int ans = 0;
        stack<int> st; 
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == '(') st.push('(');
            else {
                if(i + 1 < len && s[i+1] == ')') {
                    i++;
                }
                else {
                    ans++;
                }

                if(!st.empty()) {
                    st.pop();
                }
                else {
                    ans++;
                }
            }
        }

        ans += 2 * st.size();
        // cout << ans << endl;
        // cout << (2 * open) - close << endl;
        return ans;
    }
};