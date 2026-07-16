class Solution {
public:
    typedef long long ll;
    ll gcdSum(vector<int>& nums) {
        int n = nums.size();
        int currMax = -1;
        vector<int> prefixGcd;
        for(const auto& x: nums) {   
            currMax = max(currMax, x);
            prefixGcd.push_back(gcd(currMax, x));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        ll total = 0;
        for(int i = 0; i < (n/2); i++) {
            total += gcd(prefixGcd[i], prefixGcd[n-i-1]);
        }
        return total;
    }
};