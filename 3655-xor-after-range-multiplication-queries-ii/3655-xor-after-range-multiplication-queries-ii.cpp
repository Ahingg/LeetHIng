class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    typedef tuple<ll, ll, ll> tll;

    ll power(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while(exp > 0) {
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    ll modInverse(ll n) {
        return power(n, MOD-2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int size = sqrt(n);
        vector<vector<tll>> groups(size+1);
        for(const auto& query: queries){
            int start = query[0], end = query[1], k = query[2], val = query[3];
            if(k <= size) {
                // add to bucket
                groups[k].push_back({start, end, val});
            } 
            else {
                for(int i = start; i <= end; i += k) {
                    nums[i] = (1LL * nums[i] * val) % MOD;
                }
            }
        }
        for(int k = 1; k <= size; k++) {
            if(groups[k].empty()) continue;
            vector<ll> diff(n + k + 1, 1);
            for(auto& q: groups[k]) {
                auto& [start, end, val] = q;
                diff[start] = (diff[start] * val) % MOD;

                int step = (end - start) / k;
                int lastIndex = start + (step * k);
                int afterLast = lastIndex + k;

                diff[afterLast] = (diff[afterLast] * modInverse(val)) % MOD;
                
            }
            for(int i = 0; i < n; i++) {
                if(i >= k) {
                    diff[i] = (diff[i] * diff[i-k])%MOD;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }


        int result = 0;
        for(const auto& x: nums) {
            result ^= x;
        }
        return result;
    }
};