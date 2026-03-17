class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] && i > 0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            vector<int> temp = matrix[i];
            sort(temp.begin(), temp.end(), greater<int>());

            for(int j = 0; j < n; j++){
                result = max(result, temp[j] * (j + 1));
            }
        }

        return result;
    }
};