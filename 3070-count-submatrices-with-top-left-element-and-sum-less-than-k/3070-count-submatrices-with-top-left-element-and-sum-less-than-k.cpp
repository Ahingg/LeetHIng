class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) prefix[i][j] = grid[i][j];
                else if(i == 0) prefix[i][j] = grid[i][j] + prefix[i][j-1];
                else if(j == 0) prefix[i][j] = grid[i][j] + prefix[i-1][j];
                else {
                    prefix[i][j] = grid[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
                }
                if(prefix[i][j] > k) {
                    n = j+1;
                    break;
                }
                result++;
            }
        }
        return result;
    }
};