class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;
    void fillWith1(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 1;
        if(i > 0 && grid[i-1][j] == 0) fillWith1(i-1, j, grid); 
        if(j > 0 && grid[i][j-1] == 0) fillWith1(i, j-1, grid); 
        if(j < m - 1 && grid[i][j+1] == 0) fillWith1(i, j+1, grid);
        if(i < n - 1 && grid[i+1][j] == 0) fillWith1(i+1, j, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));
        // cek per cell

        // flood fill bagian yang pasti menyalahi aturan dengan 1: pinggir grid.
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 0) fillWith1(0, i, grid);
            if(grid[n-1][i] == 0) fillWith1(n-1, i, grid);
        }
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) fillWith1(i, 0, grid);
            if(grid[i][m-1] == 0) fillWith1(i, m-1, grid);
        }
        // ketika ketemu 0, floodfill, jawaban tambah 1
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    fillWith1(i, j, grid);
                    ans++;
                }

            }
        }
        return ans;
    }

};