class Solution {
public:
    typedef long long ll;
    typedef vector<vector<ll>> vll;
    const int MOD = 1e9 + 7;
    int totalDim; 
    vll multiply(const vll& A, const vll& B) {
        vll C(totalDim, vector<ll>(totalDim, 0));
        for (int i = 0; i < totalDim; ++i) {
            for (int k = 0; k < totalDim; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < totalDim; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    vll power(vll A, ll p) {
        vll res(totalDim, vector<ll>(totalDim, 0));
        for (int i = 0; i < totalDim; ++i) res[i][i] = 1;
        
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        r -= l;
        l = 0;
        int range = r + 1;
        totalDim = range*2;
        vll dp(totalDim, vector<ll>(totalDim, 0));
        for(int i = 0; i < range; i++) {
            for(int j = 0; j < i; j++) dp[i][range+j] = 1;
            for(int j = i+1; j < range; j++) dp[i+range][j] = 1;
        }

        vll dpN = power(dp, n-1);
        vector<ll> vec(totalDim, 1);
        vector<ll> finalVec(totalDim, 0);
        for (int i = 0; i < totalDim; ++i) {
            for (int j = 0; j < totalDim; ++j) {
                finalVec[i] = (finalVec[i] + dpN[i][j] * vec[j]) % MOD;
            }
        }
        ll total_valid_arrays = 0;
        for (int i = 0; i < totalDim; ++i) {
            total_valid_arrays = (total_valid_arrays + finalVec[i]) % MOD;
        }

        return total_valid_arrays;
    }
};