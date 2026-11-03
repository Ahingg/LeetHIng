class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) maxVal = (nums[i] > maxVal) ? nums[i] : maxVal;
        int ans = 0;
        for(int i = 0; i < n; i++) ans += (maxVal - nums[i]);
        return ans;
    }
};