class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // queries - x, queries -> inclusive.
        // range between it.
        // prefix sum jumlah 
        // 3, 5, 6
        // 1, 1, 2

        // sort queries by time
        // sort logs by time
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> qs;
        for(int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        int l = 0, r = 0;
        vector<int> store(n+1, 0);
        vector<int> res(queries.size(), 0);
        int ans = 0;
        for(auto q: qs) {
            // geser l dan r, sambilan di geser, include dan exclude angkanya
            // ketika nyentuh 0 atau bergerak dari 0, maka
            while(r < logs.size() && logs[r][1] <= q.first) {
                // cout << "r: " << r << endl; 
                if(store[logs[r][0]] == 0) ans++;
                store[logs[r][0]]++;
                r++;
            }
            while(l < r && logs[l][1] < q.first - x) {
                // cout << "l: " << l << endl; 
                store[logs[l][0]]--;
                if(store[logs[l][0]] == 0) ans--;
                l++;
            }

            // cout << "test" << endl;
            res[q.second] = n - ans;
        }

        return res;
    }
};