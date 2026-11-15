class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++) pref[i] = (pref[i-1] + arr[i-1]) % 2;
        int odd = 0, even = 1;
        int ans = 0, MOD = 1e9+7;
        for(int i = 1; i <= n; i++) {
            if(pref[i] & 1) {
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