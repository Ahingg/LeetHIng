class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = 0, product = 1, best = 2;

        for(int r = 0; r < n; r++) {
            int x = nums[r];
            while(gcd(product, x) > 1) product /= nums[left++];
            product *= x;
            best = max(best, r - left + 1);
        }
        return best;
    }
};