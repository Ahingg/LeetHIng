class Solution {
public:
    int n;
    vector<int> bit;
    void upd(int i, int d) { for(i++; i <= n; i += i & -i) bit[i] ^= d; }
    int pre(int i) { int r = 0; for(i++; i > 0; i-= i & -i) r ^= bit[i]; return r;};
    void rangeXor(int l, int r, int d) {upd(l, d); upd(r+1, d); }
    vector<bool> palindromePath(int N, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = N;
        vector<vector<int>> g(n);
        for(auto& e: edges) { 
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int LOG = 1;
        while((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> tin(n), tout(n), dep(n, 0), it(n, 0), st;

        int timer = 0;
        st.push_back(0); tin[0] = timer++;

        while(!st.empty()) {
            int u = st.back();
            if(it[u] < (int)g[u].size()) {
                int v = g[u][it[u]++];
                if(v == up[0][u]) continue;
                up[0][v] = u; dep[v] = dep[u] + 1; tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        for(int k = 1; k < LOG; k++) {
            for(int v = 0; v < n; v++) up[k][v] = up[k-1][up[k-1][v]];
        }

        auto lca = [&](int a, int b) {
            if(dep[a] < dep[b]) swap(a,b);
            int diff = dep[a] - dep[b];
            for(int k = 0; k < LOG; k++) if(diff >> k & 1) a = up[k][a];
            if(a == b) return a;
            for(int k = LOG -1; k >= 0; k--) {
                if(up[k][a] != up[k][b]) {
                    a = up[k][a]; b = up[k][b];
                }
            }
            return up[0][a];
        };
        bit.assign(n+1, 0);

        for(int i = 0; i < n; i++) rangeXor(tin[i], tout[i], 1 << (s[i] - 'a'));

        vector<bool> ans;

        for(auto& q: queries) {
            istringstream is(q);
            string type; is >> type;
            if(type == "update") {
                int u; char c; is >> u >> c;
                if(s[u] != c) {
                    rangeXor(tin[u], tout[u], (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
                    s[u] = c;
                }
            }
            else {
                int u, v; is >> u >> v;
                int l = lca(u, v);
                int mask = pre(tin[u]) ^ pre(tin[v]) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};