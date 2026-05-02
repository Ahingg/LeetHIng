class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // the relation of each number is

        // b + 2c + 3d
        // a + 2b + 3c
        // d + 2a + 3b

        // f(1) - f(0) = a + b + c - 3d
        // f(2) - f(1) = d + a + b - 3c
        // notice 3 always exists at the end, and its always the sum with missing 1 number

        // f(i) - f(i-1) = nums[i-1, i, i+1 ... end]
        // f(i) - f(i-1) = a + b + c + d - d - 3d 
        // f(i) - f(i-1) = a + b + c + d - 4d
        // f(i) = f(i-1) + Sum - n* number moving backward;
        // its d, then c then b then a.
        int n = nums.size();
        int total = 0;
        int fPrev = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
            fPrev += (nums[i] * i);
        }
        int result = fPrev;
        for(int i = 1; i < n; i++) {
            fPrev = fPrev + total - (n * (nums[n-i]));
            result = max(result, fPrev);
        }

        return result;
    }
};