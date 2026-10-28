class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0][grid[0][0]] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                for(int k = 0; k < 1024; k++) {
                    bool ok = (i > 0 && dp[i-1][j][k]) || (j > 0 && dp[i][j-1][k]);
                    if(ok) dp[i][j][k^grid[i][j]] = 1;
                }
            }
        }

        for(int i = 0; i < 1024; i++) {
            if(dp[m-1][n-1][i] == 1) return i;
        }
        return -1;
    }
};