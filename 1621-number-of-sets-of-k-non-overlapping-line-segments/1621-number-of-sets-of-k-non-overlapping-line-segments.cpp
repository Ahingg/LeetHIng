class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9+7;
    
    ll modPow(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    ll modInverse(ll n) {
        return modPow(n, MOD - 2);
    }
    ll f(ll n) {
        ll result = 1;
        for(ll i = 2; i <= n; i++) {
            result = (result * i)%MOD;
        }
        return result;
    }

    int numberOfSets(int n, int k) {
        // n + k - 1
        // 2k
        // (n+k-1)!
        // (2k)! (n-k-1)!
        ll num = f(n+k-1);
        ll num2 = ((f(2*k) * f(n-k-1)) % MOD);

        return (num * modInverse(num2)) % MOD;
    }
};