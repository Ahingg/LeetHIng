class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        if(n == 1) return 1;
        ll currentResult = 1;
        int currLen = 1;
        for(int i = 2; i <= n; i++){
            if((i & i-1) == 0) currLen++;
            currentResult = ((currentResult << currLen) + i)%MOD;
        }
        return currentResult;
    }
};