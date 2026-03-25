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
            }
            if(i > 0) sumH[i] += sumH[i-1];
        }
        ll total = sumH[m-1];
        if(total % 2 == 1) return false;
        
        for(auto x: sumH) {
            if(x*2 == total) return true;
            // cout << x << " ";
        }
        // cout << endl;
        ll f = 0;
        for(auto x: sumV) {
            f += x;
            if(f*2 == total) return true;
            // cout << x << " ";
        }
        // cout << endl;
        return false;
    }
};