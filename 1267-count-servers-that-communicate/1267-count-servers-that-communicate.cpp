class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(),  n = grid[0].size();
        int ans = 0;
        vector<int> downPass(n, 0);
        vector<int> rightPass(m, 0);
        // intinya yang penting setiap sel merassa mereka aman karena memreka bisa yakin "ga sendiri"
        // YUBISAKE DE KUMO WO NAZOTTE BOKU NI WA MIENAI MONO
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