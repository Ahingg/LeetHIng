class Solution {
public:
    typedef tuple<int, int, int, int, int> t4i; // x, y, energy      
    typedef pair<int, int> pii;  

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].length();
        
        int startY = -1, startX = -1;
        vector<pii> targets;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    startY = i; startX = j;
                }
                else if ( classroom[i][j] == 'L') {
                    targets.push_back({i, j});
                }
                
            }
        }

        int K = targets.size();
        int fullMask = (1 << K) - 1;
        if(K == 0) return 0; 
        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>((1 << K), -1)));
        queue<t4i> q;
        q.push({startY, startX, energy, 0, 0});
        maxEnergy[startY][startX][0] = energy;
        while(!q.empty()) {
            auto [y, x, e, d, mask] = q.front();
            q.pop();
            if(mask == fullMask) return d;
            if(e == 0) continue;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(classroom[ny][nx] == 'X') continue;

                int nextE = e - 1;
                if(classroom[ny][nx] == 'R') nextE = energy;
                if(nextE < 0) continue;
                int nextMask = mask;
                for(int t = 0; t < K; t++) {
                    if(targets[t].first == ny && targets[t].second == nx) {
                        nextMask |= (1 << t);
                        break;
                    }
                }
                if(nextE > maxEnergy[ny][nx][nextMask]) {
                    maxEnergy[ny][nx][nextMask] = nextE;
                    q.push({ny, nx, nextE, d+1, nextMask});
                }
            }
        }

        return -1;
        
    }
};