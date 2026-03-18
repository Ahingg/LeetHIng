class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] > k) return 0;
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        int result = 1;
        
        prefix[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            prefix[0][i] = grid[0][i] + prefix[0][i-1];
            if(prefix[0][i] <= k) result++;
        }
        for(int i = 1; i < m; i++) {
            prefix[i][0] = grid[i][0] + prefix[i-1][0];
            if(prefix[i][0] <= k) result++;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                prefix[i][j] = grid[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
                if(prefix[i][j] <= k) result++;
            }
        }
        return result;
    }
};