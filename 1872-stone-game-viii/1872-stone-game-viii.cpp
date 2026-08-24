class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i < n; i++) nums[i] += nums[i-1];
        int ans = nums[n-1];
        for(int i = n-2; i > 0; i--) ans = max(ans, nums[i] - ans);
        return ans;
    }
};