class Solution {
public:
    const int INF = 1e9;

    int dist(int i, int j, int k){
        return (j-i) + (k-j) + (k-i);
    }

    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> table(n+1);
        int result = INF;
        for(int i = 0; i < n; i++) {
            auto &tab = table[nums[i]];
            tab.push_back(i);
            int s = tab.size();
            if(s >= 3) {
                result = min(result, dist(tab[s-3], tab[s-2], tab[s-1]));
            }
        }

        return result == INF ? -1 : result;
    }
};