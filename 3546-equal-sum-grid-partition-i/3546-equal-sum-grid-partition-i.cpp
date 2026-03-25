class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> sum(m, vector<ll>(n,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) sum[i][j] = grid[i][j];
                else sum[i][j] = sum[i][j-1] + grid[i][j];
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                sum[i][j] += sum[i-1][j];
            }
        }
        // for(auto a: sum) {
        //     for(auto x: a) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        ll total = sum[m-1][n-1];
        for(int i = 0; i < m; i++){
            if(sum[i][n-1] == (total - sum[i][n-1])) return true;
        }
        for(int i = 0; i < n; i++){
            if(sum[m-1][i] == (total - sum[m-1][i])) return true;
        }
        return false;
    }
};