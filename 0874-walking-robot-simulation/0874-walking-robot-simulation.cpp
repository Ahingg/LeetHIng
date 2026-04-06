class Solution {
public:
    int dist(int x, int y) {
        return (x*x) + (y*y);
    }

    int rotate(int idx, bool clockwise) {
        return (idx + (clockwise ? 1 : -1) + 4) % 4;
    }

    long long hash(long long x, long long y){
        return (60010 * x) + y;
    }

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int directionIdx = 0;
        int posX = 0, posY = 0;
        // rotate 90 then vx will be 1 and vy will be 0;
        // rotate 90 again then vx -1, vy = 0
        int n = commands.size();
        int result = 0;
        set<long long> obsList;
        for(auto x: obstacles) {
            obsList.insert(hash(x[0], x[1]));
        }
        for(int i = 0; i < n; ++i){
            if(commands[i] < 0) {
                directionIdx = rotate(directionIdx, commands[i] == -1 ? true : false); 
            }
            else {
                for(int x = 1; x <= commands[i]; x++) {
                    int mx = dir[directionIdx][0];
                    int my = dir[directionIdx][1];
                    if(obsList.count(hash(mx + posX, my + posY))) {
                        break;
                    }
                    posX += mx;
                    posY += my;
                    result = max(result, dist(posX, posY));
                }
            }
        } 
        return result;
    }
};