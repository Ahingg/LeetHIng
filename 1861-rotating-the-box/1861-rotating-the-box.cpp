class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for(int i = 0; i < n; i++) {
            int stoneCount = 0;
            int lastObsIndex = -1;
            for(int j = 0; j < m; j++) {
                if(boxGrid[i][j] == '*') {
                    int idx = j-1;
                    int emptyCount = j - stoneCount;
                    while(idx > lastObsIndex) {
                        if(stoneCount) {
                            boxGrid[i][idx] = '#';
                            stoneCount--;
                        }
                        else {
                            boxGrid[i][idx] = '.';
                        }
                        idx--;
                    }
                    lastObsIndex = j;
                }
                else if(boxGrid[i][j] == '#') stoneCount++;
            }
            int idx = m-1;
            int emptyCount = m - stoneCount - 1;   
            // cout << stoneCount << " " << idx << endl; 
            while(idx > lastObsIndex) {
                if(stoneCount) {
                    boxGrid[i][idx] = '#';
                    stoneCount--;
                }
                else boxGrid[i][idx] = '.';
                idx--;
            }
        }

        vector<vector<char>> res(m, vector<char>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = boxGrid[n-j-1][i];
            }
        }

        return res;
    }
};