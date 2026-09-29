class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int len = m+n-1;
        if(len % 2 != 0 || grid[0][0] != '(' || grid[m-1][n-1] != ')') return false;

        vector<bitset<201>> dp(n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                bitset<201> reachable;
                if(i > 0) reachable |= dp[j];
                if(j > 0) reachable |= dp[j-1];
                if(i == 0 && j == 0) reachable.set(0);
                dp[j] = grid[i][j] == '(' ? (reachable << 1) : (reachable >> 1);
            }
        }

        return dp[n-1].test(0);
    }
};