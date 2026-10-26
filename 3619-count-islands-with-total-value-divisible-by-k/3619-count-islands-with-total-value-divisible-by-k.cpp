class Solution {
public:
    typedef long long ll;
    int K, n, m;
    
    void fill(int i, int j, ll& total, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(grid[i][j] == 0) return;
        total += grid[i][j];
        grid[i][j] = 0;
        fill(i-1, j, total, grid);
        fill(i+1, j, total, grid);
        fill(i, j-1, total, grid);
        fill(i, j+1, total, grid);
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        n = grid.size(); m = grid[0].size();
        // floodfill angka untuk cell yang bukan 0, set 0 untuk tandain jadi visited.    
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    
                    ll total = 0;
                    fill(i, j, total, grid);
                    if(total % k == 0) ans++;
                }
            }
        } 
        return ans;
    }
};