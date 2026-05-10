class Solution {
public:
    const int MININF = -1e9;
    bool valid(int a, int b, int target) {
        return abs(a-b) <= target; 
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, MININF);
        dp[0] = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(!valid(nums[i], nums[j], target) || dp[j] == MININF) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return dp[n-1] == MININF ? -1 : dp[n-1];
    }
};