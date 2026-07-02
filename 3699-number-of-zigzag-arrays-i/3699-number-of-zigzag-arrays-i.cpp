class Solution {
public:
    const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        r -= l;
        l = 0;
        int range = r + 1;
        vector<vector<int>> dpUp(n+1, vector<int>(r+1, 0));
        vector<vector<int>> dpDown(n+1, vector<int>(r+1, 0));
        for(int i = l; i <= r; i++) {
            dpUp[1][i] = 1;
            dpDown[1][i] = 1;
        }

        for(int i = 2; i <= n; i++){
            long long sumDown = 0;
            for(int j = 0; j <= r; j++) {
                dpUp[i][j] = sumDown;
                sumDown = (sumDown + dpDown[i-1][j]) % MOD;
            }

            long long sumUp = 0;
            for(int j = r; j >= 0; j--){
                dpDown[i][j] = sumUp;
                sumUp = (sumUp + dpUp[i-1][j]) % MOD; 
            }
        }

        long long result = 0;
        for(int i = 0; i <= r; i++) {
            result = (result + dpUp[n][i] + dpDown[n][i]) % MOD;
        }

        return result;
    }
};