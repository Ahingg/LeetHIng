class Solution {
public:
    const int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0, even = 1, sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum & 1) {
                ans = (ans + even) % MOD;
                odd++;
            }
            else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }
        return ans;
    }
};