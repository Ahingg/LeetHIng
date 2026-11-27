class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> f(budget + 1, 0);
        int mn = INT_MAX;
        for(auto& it: items) {
            int factor = it[0], price = it[1];
            mn = min(mn, price);
            int cnt = 0;
            for(auto& jt: items) if (jt[0] % factor == 0) cnt++;
            for(int c = budget; c >= price; c--) {
                f[c] = max(f[c], f[c-price] + cnt);
            }
        }   

        int ans = 0;
        for(int i = 0; i <= budget; i++) {
            ans = max(ans, f[i] + (budget - i) / mn);
        }
        return ans;
    }
};