class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(nums[n-1] + 3, 0);
        int ans = -1;
        for(auto x: nums) {
            dp[x+1] = dp[x] + 1;
            dp[x] = dp[x-1] + 1;
            ans = max({ans, dp[x+1], dp[x]});
        }
        return ans;
    }
    // sort arraynya
    // angkanya bisa naik kalau
    // 1 1 3 -> bisa jadi 3
    // 1 2 3 -> 3
    // 1 1 1 2 5
    // apakah max kalau dinaikin atau engga?
    // kalau ngeliat max kalau dinaikin atau engga mah mending pake max element
};