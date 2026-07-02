class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxCost = -1;
        for(auto x: costs) maxCost = max(maxCost, x);

        vector<int> arr(maxCost + 1, 0);
        for(auto x: costs) arr[x]++;
        int cnt = 0;
        for(int i = 1; i <= maxCost; i++) {
            int x = arr[i];
            if(x > 0) {
                int amt = min(x, coins / i);
                if(amt == 0) break;
                coins -= amt * i;
                cnt += amt;
            }
        }
        return cnt;
    }
};