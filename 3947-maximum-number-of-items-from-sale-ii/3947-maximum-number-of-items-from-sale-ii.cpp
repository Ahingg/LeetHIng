class Solution {
public:
    typedef pair<int, int> pii;
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n+1, 0), mult(n+1, 0);
        int mn = INT_MAX;
        for(auto& it: items) {
            cnt[it[0]]++;
            mn = min(mn, it[1]);
        }
        for(int v = 1; v <= n; v++) {
            for(int w = v; w <= n; w += v) mult[v] += cnt[w];
        }

        vector<pii> order;
        for(auto& it: items) order.push_back({it[1], mult[it[0]] - 1});
        sort(order.begin(), order.end());

        int r = budget, total = 0;
        for(auto& [p, g]: order) {
            if(p > 2 * mn || p > r) break;
            int t = min(g, r / p);
            r -= t * p;
            total += 2 * t;
            if(t < g) break;
        }
        return total + r / mn;
    }
};