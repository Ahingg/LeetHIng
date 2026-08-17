class Solution {
public:
    int dp[502][502];
    int pref[502];

    int solve(int start, int end) {
        if(start == end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int maxScore = 0;
        for(int k = start; k <= end; k++) {
            int leftSum = pref[k+1] - pref[start];
            int rightSum = pref[end+1] - pref[k+1];

            if(leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + solve(k+1, end));
            } 
            else if(leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(start, k));
            }
            else {
                maxScore = max(maxScore, leftSum + max(solve(start, k), solve(k+1, end)));
            }
        }
        return dp[start][end] = maxScore;
    }

    int stoneGameV(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(0, n-1);

    }
};