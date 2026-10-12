class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        // secara default nums[i] akan selalu diperkecil dan nums[j] akan selalu diperbesar 
        // tetatpi makin kecil nums[i] makin besar juga nums[j]
        vector<int> bits(31, 0);
        for(int x: nums) {
            int b = 0;
            while(x) {
                if(x & 1) bits[b]++;
                b++;
                x >>= 1;
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < k; i++){
            int temp = 0;
            for(int b = 0; b < 31; b++) {
                if(bits[b] > 0) {
                    temp |= (1 << b);
                    bits[b]--;
                }
            }
            ans = (ans + ((1LL * temp * temp))) % MOD; 
        }

        return ((int)ans);
    }
};