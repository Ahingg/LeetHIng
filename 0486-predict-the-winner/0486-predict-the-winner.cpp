class Solution {
public:
    typedef long long ll;
    bool predictTheWinner(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            sum += nums[i];
        } 

        for(int k = 2; k <= n; k++) {
            for(int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        // cout << dp[0][n-1];
        return dp[0][n-1] >= 0;
    }
};