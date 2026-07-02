class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int minVal = 1e9 + 5, maxVal = -1;
        for(auto x: nums) {
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }
        return 1LL * (maxVal - minVal) * k; 
    }
};