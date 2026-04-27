class Solution {
public:    
    int m, n;
    vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};
    int getNext(int sourceDir, int type) {
        if(type == 1) return ((sourceDir == 1) ? 1 : sourceDir == 3 ? 3 : -1);
        if(type == 2) return ((sourceDir == 2) ? 2 : sourceDir == 4 ? 4 : -1);
        if(type == 3) return ((sourceDir == 1) ? 2 : sourceDir == 4 ? 4 : -1); 
        if(type == 4) return ((sourceDir == 4) ? 1 : sourceDir == 3 ? 2 : -1);
        if(type == 5) return ((sourceDir == 1) ? 4 : sourceDir == 2 ? 3 : -1);
        if(type == 6) return ((sourceDir == 2) ? 1 : sourceDir == 3 ? 4 : -1);
        return -1;
    }

    bool check(int x, int y, vector<vector<int>>& grid, int incomingDir) {
        while(!(x == n-1 && y == m-1)) {
            // take the only possible way.
            // from the current incoming source, generate the next direction
            int next = getNext(incomingDir, grid[y][x]); 
            // if direction mapping passes basic validation, change the x and y based on map
            int px = x + dx[next-1], py = y + dy[next-1];
            if(px < 0 || py < 0 || px >= n || py >= m) return false;
            if(getNext(next, grid[py][px]) != -1) {
                if(py == 0 && px == 0) return false;
                x = px; y = py;
                incomingDir = next;
            }
            else return false;
        }
        return true;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        // find the possible next based on the source direction and current type;
        if(grid[0][0] == 5) return false;
        m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 4) return false;

        if(grid[0][0] == 4 && check(0,0, grid, 4)) return true;
        int incomingDir;
        if(grid[0][0] == 4) incomingDir = 3;
        else incomingDir = (grid[0][0] & 1) ? 1 : 2; 
        return check(0,0, grid, incomingDir);
    }
};