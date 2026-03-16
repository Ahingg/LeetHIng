class Solution {
public:
    vector<int> rank;
    int getMin(int i, int j, int m, int n){
        if(i == 0 && j == 0) return 0;
        int v = m-i-1;
        int h = min(n-j-1, j);
        if(i == 0) return h;
        int res = min(h,v);
        return res;
    }

    void checkAndMove(int val){
        if(val == rank[0] || val == rank[1] || val == rank[2]) return;
        if(val > rank[0]){
            rank[2] = rank[1];
            rank[1] = rank[0];
            rank[0] = val;
            return;
        }
        if(val > rank[1]){
            rank[2] = rank[1];
            rank[1] = val;
            return;
        }
        if(val > rank[2]){
            rank[2] = val;
        }
    }
    int lr[50][50];
    int rl[50][50];

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        rank.resize(3,0);
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) lr[i][j] = grid[i][j];
                else lr[i][j] = grid[i][j] + lr[i-1][j-1];

                if(i == 0 || j == n-1) rl[i][j] = grid[i][j];
                else rl[i][j] = grid[i][j] + rl[i-1][j+1];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int size = getMin(i, j, m, n);
                while(size >= 0){
                    if(size == 0) {
                        checkAndMove(grid[i][j]);
                        break;
                    }
                    int left_i = i + size, left_j = j - size;;
                    int right_i = i + size, right_j = j + size;
                    int btm_i = i + (2*size), btm_j = j;
                    // cout << "size: " << size << endl;
                    // cout << "i, j: " << i << ", " << j << endl;
                    // cout << "left i, j: " << left_i << ", " << left_j << endl;
                    // cout << "right i, j: " << right_i << ", " << right_j << endl;
                    // cout << "bottom i, j: " << btm_i << ", " << btm_j << endl;
                    size--;
                    if(btm_i >= m) {
                        checkAndMove(grid[i][j]);
                        continue;
                    } 
                    // calculate sum
                    // top to left
                    int a = rl[left_i][left_j] - ((i == 0 || j == n-1) ? 0 : rl[i-1][j+1]);
                    // top to right
                    int b = lr[right_i][right_j] - ((i == 0 || j == 0) ? 0 : lr[i-1][j-1]);
                    // right to bottom
                    int c = rl[btm_i][btm_j] - ((right_i == 0||right_j == n-1) ? 0 : rl[right_i-1][right_j+1]);
                    // left to bottom
                    int d = lr[btm_i][btm_j] - ((left_i == 0 ||left_j == 0) ? 0 : lr[left_i-1][left_j-1]);
                    int e = grid[i][j] + grid[left_i][left_j] + grid[btm_i][btm_j] + grid[right_i][right_j];
                    // printf("a,b,c,d: %d %d %d %d\n", a,b,c,d);
                    // cout << (a+b+c+d-e) << endl << endl;
                    checkAndMove((a+b+c+d-e));
                    
                }
            }
        }
        if(rank[2] == 0) rank.pop_back();
        if(rank[1] == 0) rank.pop_back();
        return rank;
    }
};