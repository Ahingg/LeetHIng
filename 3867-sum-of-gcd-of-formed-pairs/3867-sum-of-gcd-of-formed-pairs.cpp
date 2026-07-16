class Solution {
public:
    typedef long long ll;
    ll gcdSum(vector<int>& nums) {
        int n = nums.size(), currMax = -1;
        for(auto& x: nums) {   
            currMax = max(currMax, x);
            x = gcd(currMax, x);
        }
        sort(nums.begin(), nums.end());
        ll total = 0;
        for(int i = 0; i < (n/2); i++) {
            total += gcd(nums[i], nums[n-i-1]);
        }
        return total;
    }
};