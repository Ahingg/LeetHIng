class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        // check 90 clockwise
        bool result = true;
        for(int i = 0; i < n; i++){
            if(!result) break;
            for(int j = 0; j < n; j++){
                if(mat[i][j] != target[i][j]) {
                    result = false;
                    break;
                }
            }
        }

        if(result) return result;
        result = true;
        for(int i = 0; i < n; i++){
            if(!result) break;
            for(int j = 0; j < n; j++){
                if(mat[i][j] != target[j][n-i-1]) {
                    result = false;
                    break;
                }
            }
        }

        if(result) return result;

        result = true;
        for(int i = 0; i < n; i++){
            if(!result) break;
            for(int j = 0; j < n; j++){
                // cout << "i, j: " << i << " " << j << endl;
                // cout << "new i,j: " << n-j-1 << " " << n-i-1 << endl;
                if(mat[i][j] != target[n-i-1][n-j-1]) {
                    result = false;
                    break;
                }
            }
        }

        if(result) return result;

        result = true;
        for(int i = 0; i < n; i++){
            if(!result) break;
            for(int j = 0; j < n; j++){
                // cout << "i, j: " << i << " " << j << endl;
                // cout << "new i,j: " << n-j-1 << " " << n-i-1 << endl;
                if(mat[i][j] != target[n-j-1][i]) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};