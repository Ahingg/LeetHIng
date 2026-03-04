class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> rowList;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rowList[i] += mat[i][j];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            int index = -1;
            for(int j = 0; j < m; j++){
                if(mat[j][i]) index = (index == -1) ? j : -2;
                // cout << "i, j: " << i << "," << j << "| " << mat[j][i] << " " << index << endl;
                if(index == -2) break;
            }
            
            if(index > -1 && rowList[index] == 1) count++;
        }

        return count;
    }
};