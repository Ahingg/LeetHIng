class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxn = *max_element(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());
        return gcd(maxn, minn);
    }
};