class Solution {
public:
    vector<int> dx = {0, 1, -1, 0}, 
    dy = {1, 0, 0, -1};
    vector<vector<bool>> visited;
    int m, n;
    bool check(int x, int y, int xSource, int ySource, vector<vector<char>>& grid){
        visited[y][x] = true;
        bool temp = false;
        // cout << "curr " << x << " " << y << ": " << grid[y][x] << endl;
        for(int i = 0; i < 4; i++){
            int px = x + dx[i];
            int py = y + dy[i];
            // cout << "mod: " << dx[i] << " " << dy[i] << endl; 
            if(px >= 0 && py >= 0 && px < n && py < m && !(px == xSource && py == ySource)){
                // cout << "next " << px << " " << py << ": " << grid[py][px] << endl;  
                // cout << px << " " << py << " " << xSource << " " << ySource << endl;
                if(grid[py][px] == grid[y][x]) {
                    // cout << "masuk" << endl << endl;
                    if(!visited[py][px]) temp = temp || check(px, py, x, y, grid) ;
                    else temp = true;
                }
            }
        }
        // cout << endl << endl;
        return temp;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));

        bool result = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(!visited[i][j]) result = result || check(j, i, j-1, i, grid);
                if(result) return result;
            }
        }
        return result;
    }
};