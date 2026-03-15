class Fancy {
public:

    vector<bool> ops; // true if add, false if mul
    vector<int> opNumber, numbers, starting;
    int opCount = 0;
    const static int MOD = 1e9 + 7;
    Fancy() {
        
    }
    
    void append(int val) {
        numbers.push_back(val);
        starting.push_back(opCount);
    }
    
    void addAll(int inc) {
        ops.push_back(true);
        opNumber.push_back(inc);
        opCount++;
    }
    
    void multAll(int m) {
        ops.push_back(false);
        opNumber.push_back(m);
        opCount++;
    }
    
    int getIndex(int idx) {
        if(idx >= numbers.size()) return -1;
        // cout << "query: " << idx << endl;
        long long number = numbers[idx];
        for(int i = starting[idx]; i < opCount; i++){
            // cout << "Number: " << number << " opNumber: " << opNumber[i] << endl;  
            // cout << "Ops" << ops[i] << endl;
            if(ops[i]) number = (number + opNumber[i]) % MOD;
            else number = (number * opNumber[i]) % MOD;
        }
        numbers[idx] = number;
        starting[idx] = opCount;
        return number;
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