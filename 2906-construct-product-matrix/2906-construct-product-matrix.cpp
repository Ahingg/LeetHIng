class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mn = m*n;
        vector<int> suff(mn, 0), pref(mn, 0);

        pref[0] = grid[0][0] % MOD;
        suff[0] = grid[m-1][n-1] % MOD;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int index = (i * n + j);
                pref[index] = ((pref[index-1] % MOD) * (grid[i][j] % MOD)) % MOD;
                suff[index] = ((suff[index-1] % MOD) * (grid[m-i-1][n-j-1] % MOD))% MOD;  
            }
        }

        vector<vector<int>> p(m, vector<int>(n, 0));
        p[0][0] = suff[mn - 2];
        p[m-1][n-1] = pref[mn-2];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if((i == 0 && j == 0) || (i == m-1 && j == n-1)) continue;
                int index = (i * n + j);
                // for index x maka kalikans semuanya yang ada dari 0..x-1 dan m*n-1 sampai x+1
                p[i][j] = ((pref[index-1] % MOD) * (suff[mn - index - 2] % MOD)) % MOD;
                // cout << p[i][j] << " ";
            }
            // cout << endl;
        }
        return p;
    }
};