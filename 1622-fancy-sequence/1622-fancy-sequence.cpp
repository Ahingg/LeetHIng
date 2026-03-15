class Fancy {

public:
    typedef long long ll;
    ll add = 0;
    ll mul = 1;
    const ll MOD = 1e9 + 7;
    vector<ll> nums;
    
    Fancy() {
        
    }

    ll power(ll base, ll exp){
        ll res = 1;
        base %= MOD;
        while(exp > 0){
            if(exp%2 == 1) res = (res*base) % MOD;
            base = (base*base)%MOD; 
            exp /= 2;
        }

        return res;
    }

    ll modInverse(ll n){
        return power(n, MOD-2);
    }
    
    void append(int val) {
        ll x = (val - add + MOD) % MOD;
        x = (x*modInverse(mul)) % MOD;
        nums.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add+inc) % MOD;
    }
    
    void multAll(int m) {
        add = (add*m) % MOD;
        mul = (mul*m) % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= nums.size()) return -1;
        // // cout << "query: " << idx << endl;
        // long long number = numbers[idx];
        // for(int i = starting[idx]; i < opCount; i++){
        //     // cout << "Number: " << number << " opNumber: " << opNumber[i] << endl;  
        //     // cout << "Ops" << ops[i] << endl;
        //     if(ops[i]) number = (number + opNumber[i]) % MOD;
        //     else number = (number * opNumber[i]) % MOD;
        // }
        // numbers[idx] = number;
        // starting[idx] = opCount;
        // return number;
        return ((nums[idx] * mul) + add) % MOD; 
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */