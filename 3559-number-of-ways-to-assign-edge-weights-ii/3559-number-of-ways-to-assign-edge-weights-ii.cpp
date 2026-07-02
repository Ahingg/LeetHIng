class Solution {
public:
    int n, LOG;
    const int MOD = 1e9 + 7;
    vector<vector<int>> E;
    vector<vector<int>> up;
    vector<int> depthList;
    long long powerAndMod(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while(exp > 0) {
            // cout << exp << " ";
            if(exp & 1) res = (res*base)%MOD;
            base = (base * base)%MOD;
            exp >>= 1;
        }
        return res;
    }

    void dfs(int v, int parent,int depth) {
        depthList[v] = depth;
        up[v][0] = parent;

        for(int i = 1; i < LOG; i++) up[v][i] = up[ up[v][i-1] ][i-1];

        for(int e: E[v]) {
            if(e != parent) dfs(e, v, depth+1);
        }
    }

    int getLen(int u, int v) {
        if(depthList[u] < depthList[v]) swap(u,v);

        for(int j = LOG - 1; j >= 0; --j) {
            if(depthList[u] - (1 << j) >= depthList[v]){
                u = up[u][j];
            }
        }
        if(u == v) return u;
        for(int j = LOG - 1; j >= 0; --j) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;

        E.assign(n+1, vector<int>());
        up.assign(n+1, vector<int>(LOG, 1));
        depthList.assign(n+1, 0);

        for(auto& x: edges) {
            E[x[0]].push_back(x[1]);
            E[x[1]].push_back(x[0]);
        }

        dfs(1,1,0);
        vector<int> result;

        for(auto x: queries) {
            int u = x[0], v = x[1];
            if(u == v) result.push_back(0);
            else {
                int lca = getLen(u, v);
                int pathLen = depthList[u] + depthList[v] - (2*depthList[lca]);
                result.push_back(powerAndMod(2, pathLen-1));
            }
        }
        return result;
    }
};