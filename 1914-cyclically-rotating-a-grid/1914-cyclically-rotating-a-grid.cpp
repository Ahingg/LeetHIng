class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // k = 7;
        int layers = min(m/2, n/2);
        for(int l = 0; l < layers; l++){

            int i = l, j = l;

            int height = m - (2*l), width = (n - (2*l));
            int p = (2 * (height - 1 )) + (2 * (width)) - 2;
            int cycle = k % p;
            
            int move = cycle;
            // cout << "ASasa" << move;
            int iStart = i;
            int jStart = j;
            if(move >= width) {
                jStart += width - 1;
                move -= (width-1);
            }
            else {
                jStart += move;
                move = 0;
            }
            // cout << " sds" << move;
            if(move >= height) {
                iStart += height - 1;
                move -= height - 1;
            }
            else {
                iStart += move;
                move = 0;
            }

            if(move >= width) {
                jStart -= width - 1;
                move -= width-1;
            }
            else {
                jStart -= move;
                move = 0;
            }
            if(move >= height) {
                iStart -= height - 1;
                move -= height - 1;
            }
            else {
                iStart -= move;
                move = 0;
            }

            vector<int> tmp(p);
            for(int a = 0; a < p; a++){
                
                // cout << iStart << " " << jStart << endl;
                tmp[a] = grid[iStart][jStart];
                if(jStart == width - 1 + j) {
                    if(iStart > i)iStart--;
                    else jStart--;
                }

                else if(jStart == j) {
                    if(iStart + 1< height + i) iStart++;
                    else jStart++;
                }
                else if(iStart == height + i - 1){
                    if(jStart + 1 < width + j) jStart++;
                    else iStart--;
                }
                else if(iStart == i) {
                    if(jStart > j) jStart--; 
                    else iStart++;
                }
            }
            iStart = i; jStart = j;
            for(int a = 0; a < p; a++){
                
                // cout << iStart << " " << jStart << endl;
                grid[iStart][jStart] = tmp[a];
                if(jStart == width - 1 + j) {
                    if(iStart > i)iStart--;
                    else jStart--;
                }

                else if(jStart == j) {
                    if(iStart + 1< height + i) iStart++;
                    else jStart++;
                }
                else if(iStart == height - 1 + i){
                    if(jStart + 1 < width + j) jStart++;
                    else iStart--;
                }
                else if(iStart == i) {
                    if(jStart > j) jStart--; 
                    else iStart++;
                }
            }
            // for(int e: tmp) cout << e << " ";
            // cout << endl;
        }
        return grid;
    }

};