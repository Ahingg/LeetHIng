class Solution {
public:
    int numDistinct(string s, string t) {
        int lenT = t.length();
        int lenS = s.length();
    
        vector<unsigned long long> dp(lenT+1, 0);
        dp[lenT] = 1;

        for(int i = lenS-1; i >= 0; i--) {
            for(int j = 0; j < lenT; j++) {
                if(s[i] == t[j]) {
                    dp[j] = dp[j] + dp[j+1];
                }
            } 
        }
        return dp[0];
    }
};