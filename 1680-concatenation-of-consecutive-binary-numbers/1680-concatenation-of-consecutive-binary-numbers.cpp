class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    int getBinaryLength(int x){
        int len = 0;
        while(x){
            len++;
            x >>= 1;
        }
        return len;
    }

    int concatenatedBinary(int n) {
        if(n == 1) return 1;
        ll currentResult = 1;
        for(int i = 2; i <= n; i++){
            int len = getBinaryLength(i);
            currentResult = ((currentResult << len) + i)%MOD;
        }
        return currentResult;
    }
};