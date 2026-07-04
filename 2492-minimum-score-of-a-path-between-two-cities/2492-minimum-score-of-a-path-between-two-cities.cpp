class Solution {
public:
    typedef pair<int, int> pii;

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> E(n+1);
        for(const auto& r: roads) {
            E[r[0]].push_back({r[1], r[2]});
            E[r[1]].push_back({r[0], r[2]});
        }
        vector<bool> vis(n+1, false);
        queue<pii> q;
        q.push({1, 9999});
        int ans = 1e9;
        while(!q.empty()){
            auto [node, w] = q.front();
            q.pop();

            if(vis[node]) continue;

            for(const auto& [e, wg]: E[node]){
                vis[node] = true;
                ans = min(ans, wg);
                q.push({e, wg});
            }
        }
        return ans;
    }
};