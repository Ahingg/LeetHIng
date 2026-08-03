class Solution {
public:

    vector<vector<int>> pref;
    int MININF = -1 * 1e9;
    int n;
    int solveDp(vector<int>& dp, int start) {
        if(start >= n) return 0; 
        if(dp[start] != - 1) return dp[start];
        int result = MININF;
        for(int i = 1; i <= 3; i++) {
            if(start + i > n) break;
            result = max(result, pref[i][start] - solveDp(dp, start+i));
        }
        return dp[start] = result;
    }
    
    string stoneGameIII(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        pref.resize(4, vector<int>(n, -1));
        for(int i = 0; i < n; i++) pref[0][i] = 0;
        for(int i = 0; i < n; i++) pref[1][i] = nums[i];
        for(int i = 2; i <= 3; i++) {
            for(int j = 0; j < n - i + 1; j++) {
                pref[i][j] = pref[i-1][j] + nums[j + i - 1];
            }
        }
        // int result = -1;
        int result = solveDp(dp, 0);
        // cout << result << endl;
        // for(int i = 0; i <= 3; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << pref[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return (result > 0) ? "Alice" : ((result == 0) ? "Tie" : "Bob");
    }
};