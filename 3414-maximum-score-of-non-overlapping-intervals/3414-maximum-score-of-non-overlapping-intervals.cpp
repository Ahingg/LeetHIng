class Solution {
public:
    typedef long long ll;
    typedef pair<ll, vector<int>> plv;
    typedef tuple<int, int, int, int> t4i;

    bool isBetter(const plv& a, const plv& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<t4i> ivs; // start, end, weight, id
        for(int i = 0; i < n; i++){
            ivs.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }
        sort(ivs.begin(), ivs.end());
        vector<vector<plv>> dp(n+1, vector<plv>(5));
        for(int i = n-1; i >= 0; i--) {
            auto it = lower_bound(ivs.begin() + i + 1, ivs.end(), get<1>(ivs[i]) + 1, [](const t4i& inv, int val){
                return get<0>(inv) < val;
            });
            int next_i = distance(ivs.begin(), it);
            for(int k = 1; k <= 4; k++) {
                plv best = dp[i+1][k];
                plv take;
                take.first = (ll)get<2>(ivs[i]) + dp[next_i][k-1].first;
                take.second = dp[next_i][k-1].second;
                take.second.push_back(get<3>(ivs[i]));
                sort(take.second.begin(), take.second.end());
                if(isBetter(take, best)){
                    best = take;
                }
                dp[i][k] = best;
            }


        }

        return dp[0][4].second;
    }
};