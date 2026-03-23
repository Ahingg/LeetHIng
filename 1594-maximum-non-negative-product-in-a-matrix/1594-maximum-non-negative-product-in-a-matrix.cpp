class Solution {
public:
    typedef long long ll;
    pair<ll, ll> dp[16][16];
    const ll MOD = 1e9 + 7;
    const ll minX = -1e15, maxX = 1e15;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i = 1; i < m; i++) {
            ll x = dp[i-1][0].first * grid[i][0];
            dp[i][0] = {x, x};
        }        

        for(int j = 1; j < n; j++) {
            ll x = dp[0][j-1].first * grid[0][j];
            dp[0][j] = {x, x};
        }        
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++){
                ll x1 = dp[i][j-1].first * grid[i][j];
                ll x2 = dp[i][j-1].second * grid[i][j];
                ll x3 = dp[i-1][j].first * grid[i][j];
                ll x4 = dp[i-1][j].second * grid[i][j];

                dp[i][j] = {min({x1,x2,x3,x4}), max({x1,x2,x3,x4})};
                
            }
        }

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[i][j].second << " ";
        //     }
        //     cout << endl;
        // }

        return (dp[m-1][n-1].second < 0) ? -1 : (dp[m-1][n-1].second % MOD);
    }
};