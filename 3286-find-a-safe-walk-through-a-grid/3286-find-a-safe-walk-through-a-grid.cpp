class Solution {
public:
    typedef tuple<int, int, int> tii; // point, row, col
    
    int dirX[4] = {0,0,1,-1};
    int dirY[4] = {1,-1,0,0};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        deque<tii> pq; 
        pq.push_front({4 - grid[0][0], 0, 0});

        vector<vector<int>> history(m, vector<int>(n, 9999));
        history[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [point, row, col] = pq.front();
            pq.pop_front();

            if(row == m - 1 && col == n-1) return point < health;

            for(int i = 0; i < 4; i++) {
                int nr = row + dirY[i];
                int nc = col + dirX[i];
                if(!(nr >= 0 && nr < m && nc >= 0 && nc < n)) continue;
                int point = history[row][col] + grid[nr][nc];
                
                if(point < history[nr][nc]){
                    history[nr][nc] = point;
                    if(grid[nr][nc] == 1) pq.push_back({point, nr, nc});
                    else pq.push_front({point, nr, nc});
                }

            }

        }
        return false;
    }
};