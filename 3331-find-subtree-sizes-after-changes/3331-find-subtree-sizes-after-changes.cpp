class Solution {
public:
    vector<stack<int>> track;
    vector<vector<int>> son;
    vector<int> count;
    string s;
    void dfs(int idx, int from) {
        int charIdx = s[idx] - 'a';
        track[charIdx].push(idx);

        for(auto next: son[idx]) {
            dfs(next, idx);
        }

        if(!track[charIdx].empty()) { 
            track[charIdx].pop();
            // cout << idx << ": " << count[idx] << endl; 
            if(track[charIdx].empty()) {
                if(from == -1) return;
                // cout << "from: " << from << " +" << count[idx] << endl;
                count[from] += count[idx];
            }
            else {
                // cout << "on: " << count[track[charIdx].top()] << " +" << count[idx] << endl;
                count[track[charIdx].top()] += count[idx];
            }
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;
        track.assign(26, stack<int>()); son.assign(n, vector<int>()); count.assign(n, 1);
        for(int i = 1; i < n; i++) son[parent[i]].push_back(i);
        dfs(0, -1);
        return count;
    }
};