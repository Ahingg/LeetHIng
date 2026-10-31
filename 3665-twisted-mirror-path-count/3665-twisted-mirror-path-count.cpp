class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9+7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp_right(n+1, vector<int>(m+1, 0)), dp_down = dp_right;
        
        dp_right[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    int total = (dp_down[i][j] + dp_right[i][j]) % MOD;
                    dp_right[i][j+1] = (dp_right[i][j+1] + total) % MOD;
                    dp_down[i+1][j] = (dp_right[i+1][j] + total) % MOD;
                }
                else {
                    dp_down[i+1][j] = (dp_right[i][j] + dp_down[i+1][j]) % MOD;
                    dp_right[i][j+1] = (dp_right[i][j+1] + dp_down[i][j]) % MOD;
                }
            }
        }
        return (dp_right[n-1][m-1] + dp_down[n-1][m-1]) % MOD;
    }
};