class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& invs) {
        int n = invs.size();
        sort(invs.begin(), invs.end(), [] (const auto& a, const auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        int bound = -1;
        for(const auto& x: invs) {
            if(x[1] > bound) {
                ans++;
                bound = x[1];
            }
        }
        
        return ans;
        // int cnt = n;
        // vector<bool> deleted(n, false);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(i == j) continue;
        //         bool covered = (invs[i][0] <= invs[j][0]) && (invs[i][1] >= invs[j][1] && !deleted[j]);
        //         if(covered) {
        //             // cout << invs[i][0] << " " << invs[i][1] << endl;
        //             // cout << invs[j][0] << " " << invs[j][1] << endl;
        //             cnt--;
        //             deleted[j] = true;
        //         }
        //     }
        // }
        // return cnt;
    }
};