class Solution {
public:
    vector<vector<int>> E;
    int dfs(int v) {
        int maxDepth = -1;
        for(auto& e: E[v]) {
            maxDepth = max(maxDepth, 1 + dfs(e));
        }
        return maxDepth;
    }
    const int MOD = 1e9 + 7;
    long long powerAndMod(long long base, long long n) {
        long long res = 1;
        base %= MOD;
        while(n) {
            if(n & 1) res = (res*base)%MOD;
            base = (base * base)%MOD;
            
            n /= 2;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        E.resize(n+1), vector<int>();

        for(auto& e: edges) {
            E[e[0]].push_back(e[1]);
        }
        
        int depth = dfs(1);
        return powerAndMod(2, depth);
    }
};