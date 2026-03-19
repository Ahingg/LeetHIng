class Solution {
public:
    const int locked = 1e7;
    int getBalance(char c) {
        if(c == 'X') return 1;
        if(c == 'Y') return -1;
        return locked;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, locked));
        int result = 0;
        
        prefix[0][0] = getBalance(grid[0][0]);
        for(int i = 1; i < n; i++){
            int balance = getBalance(grid[0][i]);
            if(prefix[0][i-1] != locked) {
                prefix[0][i] = (balance == locked ? prefix[0][i-1] : prefix[0][i-1] + balance);  
            }
            else {
                prefix[0][i] = (balance == locked) ? locked : balance;
            }
            if(prefix[0][i] == 0) result++;
        }
        for(int i = 1; i < m; i++) {
            int balance = getBalance(grid[i][0]);
            if(prefix[i-1][0] != locked) {
                prefix[i][0] = (balance == locked ? prefix[i-1][0] : prefix[i-1][0] + balance);  
            }
            else {
                prefix[i][0] = (balance == locked) ? locked : balance;
            }

            if(prefix[i][0] == 0) result++;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int balance = getBalance(grid[i][j]);
                if(balance != locked) {
                    if(prefix[i][j-1] == locked && prefix[i-1][j] == locked) {
                        prefix[i][j] = balance;
                    }
                    else if(prefix[i][j-1] == locked) {
                        prefix[i][j] = balance + prefix[i-1][j];
                    }
                    else if(prefix[i-1][j] == locked) {
                        prefix[i][j] = balance + prefix[i][j-1];
                    }
                    else {
                        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + balance - (prefix[i-1][j-1] == locked ? 0 : prefix[i-1][j-1]);
                    }
                }
                else {
                    if(prefix[i][j-1] == locked && prefix[i-1][j] == locked) {
                        prefix[i][j] = balance;
                    }
                    else if(prefix[i][j-1] == locked) {
                        prefix[i][j] = prefix[i-1][j];
                    }
                    else if(prefix[i-1][j] == locked) {
                        prefix[i][j] = prefix[i][j-1];
                    }
                    else {
                        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - (prefix[i-1][j-1] == locked ? 0 : prefix[i-1][j-1]);
                    }
                }

                if(prefix[i][j] == 0) result ++;
            }
        }

        return result;
    }
};