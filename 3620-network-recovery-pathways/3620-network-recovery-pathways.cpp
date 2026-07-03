class Solution {
public:
    typedef long long ll;
    typedef pair<int, ll> pil;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = online.size();
        vector<vector<pil>> adj(n);
        vector<int> inDegree(n, 0);
        vector<int> uniqueCost;
        for(const auto& e: edges) {
            int u = e[0], v = e[1];
            ll cost = e[2];
            adj[u].push_back({v, cost});
            inDegree[v]++;
            uniqueCost.push_back(cost);
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);
            for(const auto &[to, cost]: adj[u]){
                inDegree[to]--;
                if(inDegree[to] == 0) q.push(to);
            }
        }

        sort(uniqueCost.begin(), uniqueCost.end());

        uniqueCost.erase(unique(uniqueCost.begin(), uniqueCost.end()), uniqueCost.end());

        auto isValid = [&](ll mid) -> bool {
            vector<ll> dist(n, 1e18);

            dist[0] = 0;
            for(int u: order) {
                if(dist[u] == 1e18 || !online[u]) continue;
                for(const auto& [to, cost]: adj[u]) {
                    if(cost < mid || !online[to]) continue;
                    if(dist[u] + cost < dist[to]) {
                        dist[to] = dist[u] + cost;
                    }
                } 
            }
            return dist[n-1] <= k;
        };

        int low = 0, high = (int) uniqueCost.size() - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(uniqueCost[mid])) {
                ans = uniqueCost[mid];
                low = mid + 1;
            } 
            else high = mid - 1;
        }

        return ans;

    }
};