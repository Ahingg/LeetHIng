class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + nums[i-1];
        int ans = 1e9;
        for(int s = l; s <= r; s++) {
            for(int idx = 0; idx + s - 1 < n; idx++) {
                int idx2 = idx + s;
                int sum = pref[idx2] - pref[idx];
                if(sum > 0) ans = min(ans, sum); 
            }
        } 
        return ans == 1e9 ? -1 : ans;
    }
};