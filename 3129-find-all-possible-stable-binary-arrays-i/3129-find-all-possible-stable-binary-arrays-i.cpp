class Solution {
public:
    const static int MOD = 1e9+7;
    int dp[201][201][2];
    int numberOfStableArrays(int zero, int one, int limit) {

        for(int i = 1; i <= min(zero, limit); i++) dp[i][0][0] = 1;

        for(int i = 1; i <= min(one, limit); i++) dp[0][i][1] = 1;
        
        for(int i = 1; i <= zero; i++){
            for(int j = 1; j <= one; j++){
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                if(i > limit) {
                    dp[i][j][0] = (dp[i][j][0] - dp[i-1-limit][j][1] + MOD) % MOD; 
                }

                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
                if(j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-1-limit][0] + MOD) % MOD; 
                }
            }
            
        }
        
        return (dp[zero][one][0] + dp[zero][one][1])%MOD;
    }
};