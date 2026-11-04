class Solution {
public:
    typedef long long ll;
    ll minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> vals(nums);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        vector<int> rk(n);
        for(int i = 0; i < n; i++) {
            rk[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;
        }

        vector<int> cnt(m+1, 0);
        vector<ll> sm(m+1, 0);
        int top = 1;

        while(top*2 <= m) top *= 2;
        int need = (x + 1) / 2;
        int w = n - x + 1;
        
        vector<ll> cost(w);
        ll total = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
            for(int p = rk[i]; p <= m; p += p & -p) {
                cnt[p] += 1;
                sm[p] += nums[i];
            }
            if(i >= x) {
                total -= nums[i-x];
                for(int p = rk[i-x]; p <= m; p += p & -p) {
                    cnt[p]--;
                    sm[p] -= nums[i-x];
                }
            }
            if(i >= x-1) {
                int pos = 0, rem = need;
                ll s0 = 0;
                for(int pw = top; pw > 0; pw >>= 1) {
                    int nxt = pos + pw;
                    if(nxt <= m && cnt[nxt] < rem) {
                        pos = nxt;
                        rem  -= cnt[nxt];
                        s0 += sm[nxt];
                    }
                }

                ll med = vals[pos];
                ll c0 = need - rem;
                cost[i - x + 1] = med * c0 - s0 + (total - s0) - med * (x - c0);
            }
        }

        const ll INF = 1e18 * 1LL;
        vector<ll> prev(n+1, 0 ), cur(n+1, 0);
        for(int j = 0; j < k; j++) {
            for(int i = 0; i < x; i++)  cur[i] = INF;
            for(int i = x; i <= n; i++) cur[i] = min(cur[i - 1], prev[i-x] + cost[i-x]);
            swap(prev, cur);
        }

        return prev[n];
        
        
    }
};