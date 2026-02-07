class Solution {
public:
    int dp[100005];
    int minimumDeletions(string s) {
        int len = s.length();
        int bCount = 0;
        if(s[0] == 'b') bCount++;
        for(int i = 1; i < len; i++){
            if(s[i] == 'b'){
                bCount++;
                dp[i] = dp[i-1];
            }
            else {
                // cout << bCount << " ";
                if(bCount > 0) {
                    // cout << dp[i-1] + bCount << " " << dp[i-1] + 1 << ": ";
                    dp[i] = min(bCount, dp[i-1] + 1);
                }
                else dp[i] = dp[i-1];
                cout << dp[i] << endl;
            }
        }
        return dp[len-1];
    }
};