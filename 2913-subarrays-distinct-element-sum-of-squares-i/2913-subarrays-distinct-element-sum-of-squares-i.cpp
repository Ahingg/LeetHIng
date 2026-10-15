class Solution {
public:
    typedef long long ll;
    static const ll MOD = 1e9+7;
    vector<ll> s1, s2, lz;

    void apply(int o, int len, ll k) {
        s2[o] = (s2[o] + (2 * k % MOD * s1[o]) + (k * k % MOD * len)) % MOD;
        s1[o] = (s1[o] + k * len) % MOD;
        lz[o] = (lz[o] + k) % MOD; 
    }

    void push(int o, int l, int r) {
        if(lz[o]) {
            int m = (l + r) / 2;
            apply(2 * o, m - l + 1, lz[o]);
            apply(2 * o + 1, r - m, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            apply(o, r - l + 1, 1);
            return;
        }

        push(o, l, r);
        int m = (l + r) / 2;
        if(L <= m) update(2 * o, l, m, L, R);
        if(R > m) update(2 * o + 1, m+1, r, L, R);
        s1[o] = (s1[2*o] + s1[2 * o + 1]) % MOD;
        s2[o] = (s2[2*o] + s2[2 * o + 1]) % MOD;
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s1.assign(4 * n, 0); s2.assign(4 * n, 0); lz.assign(4 * n, 0);
        unordered_map<int, int> last;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int p = last.count(nums[i]) ? last[nums[i]] : -1;
            update(1, 0, n-1, p+1, i);
            ans = (ans + s2[1]) % MOD;
            last[nums[i]] = i;
        }
        return ans;
    }
}; 