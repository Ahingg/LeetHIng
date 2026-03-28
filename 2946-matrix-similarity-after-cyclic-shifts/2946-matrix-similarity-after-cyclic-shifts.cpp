class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;
        if(k == 0) return true;
        for(int i = 0; i < m; i++) {
            int count = 0;
            // if left shift, compare from newIndex = index0, where newIndex can be calculated by projecting the first element
            int j = k;
            while(count < n) {
                if(mat[i][count] != mat[i][j]) return false;
                j = (j+1)%n;
                count++;
            }
        }
        return true;
    }
};