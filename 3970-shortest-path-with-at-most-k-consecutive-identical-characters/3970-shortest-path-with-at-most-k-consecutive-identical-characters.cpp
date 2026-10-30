class Solution {
public:
    typedef tuple<int, int, int> t4i; // total weight, consecutive, u;
    typedef pair<int, int> pii;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<pii>> E(n+1); 
        for(const auto& e: edges) {
            E[e[0]].push_back({e[1], e[2]});
        }

        int K = k+1;
        vector<int> dist(n * K, INT_MAX);
        priority_queue<t4i, vector<t4i>, greater<t4i>> pq;
        dist[0*K + 1] = 0;
        pq.push({0, 1, 0});
        while(!pq.empty()) {
            auto [w, c, u] = pq.top();
            // cout << w << " " <<  c << " " << u << endl; 
            pq.pop();
            if(w > dist[u * K + c]) continue;
            if(u == n-1) return w;

            for(auto& [v, wNext]: E[u]) {
                // cout << v << " " << wNext << endl;
                int cNew = (labels[u] == labels[v]) ? (c+1) : 1;
                if(cNew > k) continue;
                int nW = w + wNext;
                if(nW < dist[v * K + cNew]){
                    dist[v * K + cNew] = nW;
                    pq.push({nW, cNew, v});
                }
            }
            // cout << endl;
        }

        return -1;
    }
};