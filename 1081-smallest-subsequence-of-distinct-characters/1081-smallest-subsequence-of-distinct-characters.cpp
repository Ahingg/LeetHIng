class Solution {
public:
    string smallestSubsequence(string s) {
        int len = s.length();
        
        vector<int> freq(26, 0);
        for(const char& c: s) {
            freq[c-'a']++;
        }
        stack<int> st;
        int seen = 0;

        for(const char& c: s){
            int idx = c - 'a';
            freq[idx]--;

            if(seen & (1 << (idx))) continue;
            while(!st.empty() && st.top() > (idx) && freq[st.top()]) {
                seen -= (1 << st.top());
                st.pop();
            }

            st.push(idx);
            seen = seen | (1 << (idx));
        }
        string ans = "";
        while(!st.empty()) {
            ans += ('a' + st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};