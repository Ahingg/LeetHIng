class Solution {
public:
    typedef long long ll;
    vector<ll> resultArray(vector<int>& nums, int k) {
        // nums max = 10^9 ^ 10^5
        // untuk nyari 1 anga berarti:
        // range x sampe y kalau dikaliin, MOD k jadi x ga?
        ll n = nums.size();
        vector<ll> dp(k, 0);

        vector<ll> ans(k, 0);

        for(int i = 0; i < n; i++) {
            vector<ll> dpNext(k, 0);
            dpNext[nums[i] % k]++;
            for(int x = 0; x < k; x++) {
                if(dp[x] <= 0) continue;
                ll rem = (1LL * x * nums[i]) % k;
                dpNext[rem] += dp[x];
            }
            for(int x = 0; x < k; x++) {
                ans[x] += dpNext[x];
                dp[x] = dpNext[x];
            }
        }
        return ans;
    }
};