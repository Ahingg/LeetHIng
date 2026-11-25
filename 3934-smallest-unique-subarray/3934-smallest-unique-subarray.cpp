class Solution {
public:
    typedef unsigned long long ull;
    static constexpr ull MOD = (1ULL << 61) - 1;
    int n;
    vector<ull> pre, pw;
    static ull mulmod(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull r = (ull) (t & MOD) + (ull) (t >> 61);
        return r >= MOD ? r - MOD : r;
    }

    ull get(int l, int r) {
        ull x = pre[r] + MOD - mulmod(pre[l], pw[r-l]);
        return x >= MOD ? x - MOD : x;
    }

    bool hasUnique(int L) {
        int m = n - L + 1;
        vector<ull> h(m);
        for(int i = 0; i < m; i++) h[i] = get(i, i + L);
        sort(h.begin(), h.end());
        for(int i = 0; i < m; i++) {
            bool prevSame = i > 0 && h[i] == h[i-1];
            bool nextSame = i + 1 < m && h[i] == h[i+1];
            if(!prevSame && !nextSame) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        ull B = 1000003 + rng() % (MOD - 2000000);

        pre.assign(n + 1, 0); pw.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = mulmod(pre[i], B) + nums[i];
            if (pre[i + 1] >= MOD) pre[i + 1] -= MOD;
            pw[i + 1] = mulmod(pw[i], B);
        }

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (hasUnique(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};