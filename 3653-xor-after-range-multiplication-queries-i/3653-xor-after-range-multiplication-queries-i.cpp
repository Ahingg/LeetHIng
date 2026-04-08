class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(const auto& query: queries){
            int start = query[0], end = query[1], offset = query[2], val = query[3];

            for(int i = start; i <= end; i += offset) {
                nums[i] = (1LL * val * nums[i]) % MOD;
            }
        }

        int result = 0;
        // cout << nums[0] << " ";
        for(const auto& x: nums) {
            // cout << nums[i] << " ";
            result ^= x;
        }
        return result;
    }
};