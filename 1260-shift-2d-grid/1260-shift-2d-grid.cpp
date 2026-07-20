class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= (m*n);
        if(k == 0) return grid;

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // cout << n << endl;
                int j1 = (j + k) % n;
                int i1 = (i + ((j + k) / n)) % m;
                // cout << i1 << " " << j1 << endl;
                ans[i1][j1] = grid[i][j];
            }
        }

        return ans;

    }
};