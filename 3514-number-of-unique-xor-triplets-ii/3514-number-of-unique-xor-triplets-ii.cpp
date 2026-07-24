class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> xo(2049, false);
        for(int j = 0; j < n; j++) {
            for(int k = j; k < n; k++) {
                xo[nums[j] ^ nums[k]] = true;
            }
        }
        vector<bool> ans(2049, false);
        int uniq = 0;
        for(int i = 0; i < n; i++) {
            for(int a = 0; a < 2049; a++) {
                if(xo[a]) {
                    int idx = a ^ nums[i];
                    if(ans[idx]) continue;
                    ans[idx] = true;
                    uniq++;
                }
            }
        }
        return uniq;
    }
};