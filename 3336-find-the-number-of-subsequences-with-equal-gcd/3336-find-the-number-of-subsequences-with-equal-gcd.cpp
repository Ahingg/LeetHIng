class Solution {
public:
    const int MOD = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 

        int n = nums.size();

        int maxNum = 0;
        for(auto x: nums) maxNum = max(maxNum, x);
        // cout << "test";

        vector<vector<int>> dp(maxNum+1, vector<int>(maxNum+1, 0));
        dp[0][0] = 1;
        for(auto num: nums) {
            vector<vector<int>> nextDp = dp;
            for(int i = 0; i <= maxNum; i++) {
                for(int j = 0; j <= maxNum; j++) {
                    if(dp[i][j] == 0) continue;
                    int next1 = gcd(i, num);
                    nextDp[next1][j] = (nextDp[next1][j] + dp[i][j]) % MOD;
                
                    int next2 = gcd(j, num);
                    nextDp[i][next2] = (nextDp[i][next2] + dp[i][j]) % MOD;
                }
            }
                dp = move(nextDp);
        }
        int ans = 0;
        for(int i = 1; i <= maxNum; i++) {
            ans = (ans + dp[i][i]) % MOD;
        }
        return ans;
    }
};