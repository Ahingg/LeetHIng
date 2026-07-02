class Solution {
public:
    typedef pair<int, int> pii;
    int maxBuilding(int n, vector<vector<int>>& res) {
        int r = res.size();
        if(r == 0) return n-1;

        vector<pii> rs;
        rs.push_back({1,0});
        for(auto &x: res) rs.push_back({x[0], x[1]});
        sort(rs.begin(), rs.end());
        if(rs[r].first != n) rs.push_back({n, n-1});

        r = rs.size();
        for(int i = 1; i < r; i++){
            rs[i].second = min(rs[i].second, rs[i-1].second + (rs[i].first - rs[i-1].first));
            // cout << rs[i].first << " " << rs[i-1].first << " | " << rs[i].second << " " << rs[i-1].second << endl;
        }
        // cout <<  endl;
        for(int i = r-2; i >= 0; i--){

            rs[i].second = min(rs[i].second, rs[i+1].second + (rs[i+1].first - rs[i].first));
        }

        // cout << endl;
        int currMax = -1;
        for(int i = 0; i < r-1; i++){
            // cout << rs[i+1].first << " " << rs[i].first << " | " << rs[i+1].second << " " << rs[i].second << endl;
            int res = ((rs[i+1].first - rs[i].first) + rs[i+1].second + rs[i].second) / 2;
            currMax = max(currMax, res);
        }
        return currMax;
    }
};