class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1, ans = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]) inc++;
            else inc = 1;

            if(nums[i-1] > nums[i]) dec++;
            else dec = 1;

            ans = max({inc, dec, ans});
        }
        return ans;
    }
};