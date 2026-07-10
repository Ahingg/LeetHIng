class Solution {
public:

    typedef pair<int,int> pii;
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<pii> sorted(n);
        for(int i = 0; i < n; i++) sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end());

        vector<int> toSorted(n);
        for(int i = 0; i < n; i++) toSorted[sorted[i].second] = i;

        vector<int> connection(n, 0);
        int group = 0;
        for(int i = 1; i < n; i++) {
            auto& [val, index] = sorted[i];
            auto& [val1, index1] = sorted[i-1];
            if(val - val1 > maxDiff) group++;
            connection[i] = group;
        } 

        int maxLog = 18;
        vector<vector<int>> up(maxLog, vector<int>(n));
        int r = 0;
        for(int l = 0;  l < n; l++) {
            auto& [lVal, lIdx] = sorted[l];
            while(r < n && (sorted[r].first - lVal <= maxDiff)) r++;
            up[0][l] = r-1;
        }

        for(int i = 1; i < maxLog; i++) {
            for(int j = 0; j < n; j++) {
                up[i][j] = up[i-1][up[i-1][j]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for(const auto& q: queries) {
            int a = q[0], b = q[1];

            if(a == b) ans.push_back(0);
            else {
                int x = toSorted[a], y = toSorted[b];
                if(x > y) swap(x, y);

                if(connection[x] != connection[y]) {
                    ans.push_back(-1);
                    continue;
                }

                if(up[0][x] >= y) {
                    ans.push_back(1);
                    continue;
                }

                int steps = 0;

                for(int k = maxLog - 1; k >= 0; k--) {
                    if(up[k][x] < y) {
                        x = up[k][x];
                        steps += (1 << k);
                    }
                }
                ans.push_back(steps + 1);
            }
        }

        return ans;
    }
};