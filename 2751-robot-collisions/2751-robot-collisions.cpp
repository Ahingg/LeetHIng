class Solution {
public:

    typedef tuple<int, int, int, char> stats; // positio, index, health, directions;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        priority_queue<stats, vector<stats>, greater<stats>> stat_queue;

        vector<int> q(n);
        iota(q.begin(), q.end(), 0);

        sort(q.begin(), q.end(), [&](int i, int j){
            return positions[i] < positions[j];
        });

        stack<int> remaining;
        for(auto x: q) {
            if(directions[x] == 'R') {
                remaining.push(x);
                continue;
            }
            
            while(!remaining.empty() && healths[x] != 0) {
                int idx = remaining.top();
                if(healths[idx] < healths[x]) {
                    healths[idx] = 0;
                    healths[x]--;
                    remaining.pop();
                }
                else if(healths[x] < healths[idx]) {
                    healths[x] = 0;
                    healths[idx]--;
                }
                else {
                    healths[x] = 0;
                    healths[idx] = 0;
                    remaining.pop();
                }
            }

            // cout << idx << ": " << pos << " " << health << " " << dir << endl;
            // if(remaining.empty() || dir == 'R') {
            //     remaining.push({pos, idx, health, dir});
            //     continue;
            // }
            // bool same = false;
            // while(!remaining.empty()){ 
            //     auto [posT, idxT, healthT, dirT] = remaining.top();
            //     if(!(dir == 'L' && dirT == 'R')) break;
            //     remaining.pop();
            //     // cout << "New T for: "<< idxT << ": " << posT << " " << health << " " << dirT << endl;
            //     if(healthT == health) {
            //         healths[idxT] = 0;
            //         healths[idx] = 0;
            //         same = true;
            //         break;
            //     }
            //     if(healthT > health) {
            //         healths[idx] = 0;
            //         healths[idxT]--;
            //         healthT--;
            //         pos = posT; idx = idxT; health = healthT; dir = dirT;
            //         break;
            //     }
            //     else {
            //         healths[idxT] = 0;
            //         healths[idx]--;
            //         health--;
            //     }
            // }
            // // cout << "top: index: " << idx << ": " << pos << " " << health << " " << dir << endl;
            // if(!same) remaining.push({pos, idx, health, dir});
        }

        vector<int> result;
        for(auto x: healths) {
            if(x) result.push_back(x);
        }
        return result;
    }
};