class Solution {
public:
    int maxDepth(string s) {
        int n = 0;
        int ans = -1;
        for(const char& c: s) {
            if(c == '(') n++;
            if(c == ')') n--;
            ans = max(ans, n);
        }
        return ans;
    }
};