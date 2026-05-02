class Solution {
public:
    const int INF = 1e9;

    const int cost[3] = {0, 1, 1};
    const int value[3] = {0, 1, 2};

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        int start = cost[grid[0][0]];
        if(start <= k) {
            dp[0][start] = value[grid[0][0]];
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int currCost = cost[grid[i][j]];
                int currVal = value[grid[i][j]];

                vector<int> next(k + 1, -1);

                for(int c = currCost; c <= k; c++) {
                    int prevCost = c - currCost;
                    int maxPrev = -1;

                    if(dp[j][prevCost] != -1) maxPrev = max(dp[j][prevCost], maxPrev);
                    if(j > 0 && dp[j-1][prevCost] != -1) maxPrev = max(dp[j-1][prevCost], maxPrev);
                    if(maxPrev != -1) next[c] = maxPrev + currVal;
                }
                
                dp[j] = next; 
            }
        }

        int maxAns = -1;
        for(int i = 0; i <= k; i++) {
            maxAns = max(maxAns, dp[n-1][i]);
        }
        return maxAns;
    }
};