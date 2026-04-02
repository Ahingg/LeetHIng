class Solution {
public:
    const int INF = -1e9;
    int dp[501][3];
    // belajar
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < 3; k++){
                dp[j][k] = INF;
            }
        }
        dp[1][0] = dp[1][1] = dp[1][2] = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[j+1][2] = max(max(dp[j+1][2], dp[j][2]) + coins[i][j], max(dp[j+1][1], dp[j][1]));
                dp[j+1][1] = max(max(dp[j+1][1], dp[j][1]) + coins[i][j], max(dp[j+1][0], dp[j][0]));
                dp[j+1][0] = max(dp[j+1][0], dp[j][0]) + coins[i][j];
            }
        }
        return dp[n][2];
    }
    // Solution ahing
    // const int INF = -1e9;
    // int dp[501][501][3];
    // int maximumAmount(vector<vector<int>>& coins) {
    //     int m = coins.size(), n = coins[0].size();
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             for(int k = 0; k < 3; k++){
    //                 dp[i][j][k] = INF;
    //             }
    //         }
    //     }

    //     dp[0][0][0] = coins[0][0];
    //     dp[0][0][1] = coins[0][0] < 0 ? 0 : INF;

    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(i == 0 && j == 0) continue;
    //             if(i == 0) {
    //                 // take from left only
    //                 dp[i][j][0] = dp[i][j-1][0] + coins[i][j];
    //                 if(coins[i][j] >= 0) {
    //                     dp[i][j][1] = dp[i][j-1][1] == INF ? INF : dp[i][j-1][1] + coins[i][j];
    //                     dp[i][j][2] = dp[i][j-1][2] == INF ? INF : dp[i][j-1][2] + coins[i][j];
    //                 }
    //                 else {
    //                     dp[i][j][1] = max(dp[i][j-1][0], dp[i][j-1][1] + coins[i][j]);
    //                     dp[i][j][2] = max(dp[i][j-1][1], dp[i][j-1][2] + coins[i][j]);
    //                 }
    //             }
    //             else if(j == 0) {
    //                 dp[i][j][0] = dp[i-1][j][0] + coins[i][j];
    //                 if(coins[i][j] >= 0) {
    //                     dp[i][j][1] = dp[i-1][j][1] == INF ? INF : dp[i-1][j][1] + coins[i][j];
    //                     dp[i][j][2] = dp[i-1][j][2] == INF ? INF : dp[i-1][j][2] + coins[i][j];
    //                 }
    //                 else {
    //                     dp[i][j][1] = max(dp[i-1][j][0], dp[i-1][j][1] + coins[i][j]);
    //                     dp[i][j][2] = max(dp[i-1][j][1], dp[i-1][j][2] + coins[i][j]);
    //                 }
    //             }
    //             else {
    //                 // take max from up and left
    //                 dp[i][j][0] = max(dp[i-1][j][0] + coins[i][j], dp[i][j-1][0] + coins[i][j]);
    //                 if(coins[i][j] >= 0) {
    //                     dp[i][j][1] = dp[i-1][j][1] == INF ? INF : dp[i-1][j][1] + coins[i][j];
    //                     dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1] == INF ? INF : dp[i][j-1][1] + coins[i][j]);
    //                     dp[i][j][2] = dp[i-1][j][2] == INF ? INF : dp[i-1][j][2] + coins[i][j];
    //                     dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][2] == INF ? INF : dp[i][j-1][2] + coins[i][j]);
    //                 }
    //                 else {
    //                     dp[i][j][1] = max(max(dp[i-1][j][0], dp[i-1][j][1] + coins[i][j]), max(dp[i][j-1][0], dp[i][j-1][1] + coins[i][j]));
    //                     dp[i][j][2] = max(max(dp[i-1][j][1], dp[i-1][j][2] + coins[i][j]), max(dp[i][j-1][1], dp[i][j-1][2] + coins[i][j]));
    //                 }
    //             }
    //             // cout << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << endl;
    //         }
    //         // cout << endl;
    //     }
    //     return max(dp[m-1][n-1][0], max(dp[m-1][n-1][1], dp[m-1][n-1][2]));
    // }
};