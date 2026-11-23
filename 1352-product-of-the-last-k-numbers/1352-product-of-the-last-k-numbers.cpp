class ProductOfNumbers {
public:
    // gimana cara ngejawab apakah ada 0 di range k?
    // kita bisa coba buat counter 0 yang ada di sebuah list, ketika ketemu 0 maka jumlahnya bertambah, dan saat di eliminasi hasilnya > 0, maka ada 0.
    typedef long long ll;
    const ll MOD = 2147483659LL;
    ll inv_num[101];
    vector<ll> prefix, invPrefix;

    ll modPow(ll base, ll exp) {
        ll res = 1;
        while(exp > 0) {
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    ProductOfNumbers() {
        for(int i = 1; i <= 100; i++) {
            inv_num[i] = modPow(i, MOD-2);
        }
        prefix.push_back(1);
        invPrefix.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            prefix.clear();
            invPrefix.clear();
            prefix.push_back(1);
            invPrefix.push_back(1);
        }
        else {
            prefix.push_back((prefix.back() * num) % MOD);
            invPrefix.push_back((invPrefix.back() * inv_num[num]) % MOD);
        }
    }
    
    int getProduct(int k) {
        int n = (int) (prefix.size()) - 1;
        if(k > n) return 0;
        return (int) ((prefix[n] * invPrefix[n-k]) % MOD);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */