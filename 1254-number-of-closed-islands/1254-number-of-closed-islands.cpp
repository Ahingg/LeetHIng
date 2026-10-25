class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;
    bool fillWith1(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(grid[i][j] == 1) return true;
        
        grid[i][j] = 1;

        bool down = fillWith1(i+1, j, grid), up = fillWith1(i-1, j, grid);
        bool left = fillWith1(i, j-1, grid), right = fillWith1(i, j+1, grid);
        return down && up && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));
        // cek per cell

        // flood fill bagian yang pasti menyalahi aturan dengan 1: pinggir grid.
        // ketika ketemu 0, floodfill, jawaban tambah 1
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 && fillWith1(i, j, grid)) ans++;

            }
        }
        return ans;
    }

};