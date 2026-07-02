class Solution {
public:
    typedef pair<int, int> pii;
    typedef tuple<int, int, int> tii;

    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pii> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i,j});
                } 
            }
        } 

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nRow = row + dirY[i];
                int nCol = col + dirX[i];
                if(!(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n)) continue;
                if(safeness[nRow][nCol] != -1) continue;
                safeness[nRow][nCol] = safeness[row][col] + 1;
                q.push({nRow, nCol});
            }
        }
        vector<vector<int>> history(n, vector<int>(n, -1));
        priority_queue<tii> pq;

        history[0][0] = safeness[0][0];
        pq.push({history[0][0], 0, 0});

        while(!pq.empty()) {
            auto [point, row, col] = pq.top();
            pq.pop();

            if(row == n-1 && col == n-1) return point;

            for(int i = 0; i < 4; i++) {
                int nRow = row + dirY[i];
                int nCol = col + dirX[i];

                if(!(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n)) continue;

                int currPoint = min(point, safeness[nRow][nCol]);
                if(currPoint > history[nRow][nCol]) {
                    history[nRow][nCol] = currPoint;
                    pq.push({currPoint, nRow, nCol});
                }
            }
        }

        return 0;
    }
};