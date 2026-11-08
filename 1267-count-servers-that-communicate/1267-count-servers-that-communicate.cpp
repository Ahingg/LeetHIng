class Solution {
public:
    int m, n;
    bool check(vector<vector<int>>& grid, int i, int j){
        if(i + 1 < m && grid[i+1][j] == 1) return true;
        if(j + 1 < n && grid[i][j+1] == 1) return true;
        if(i - 1 >= 0 && grid[i-1][j] == 1) return true;
        if(j - 1 >= 0 && grid[i][j-1] == 1) return true;
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0;
        vector<int> downPass(n, 0);
        vector<int> rightPass(m, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    downPass[j]++;
                    rightPass[i]++;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && (downPass[j] > 1 || rightPass[i] > 1)) ans++;
            }
        }
        return ans;
    }
};