class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> sumH(m, 0), sumV(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                sumH[i] += grid[i][j];
                sumV[j] += grid[i][j];
                if(j > 0 && i == m - 1) sumV[j] += sumV[j-1];
            }
            if(i > 0) sumH[i] += sumH[i-1];
        }
        if(sumH[m-1] % 2 == 1) return false;
        
        for(auto x: sumH) {
            if(x*2 == sumH[m-1]) return true;
            // cout << x << " ";
        }
        // cout << endl;
        for(auto x: sumV) {
            if(x*2 == sumV[n-1]) return true;
            // cout << x << " ";
        }
        // cout << endl;
        return false;
    }
};