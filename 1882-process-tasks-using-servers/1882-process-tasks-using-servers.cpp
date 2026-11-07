class Solution {
public:
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef tuple<long long, int, int> tlii;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<pii, vector<pii>, greater<pii>> serverFree;
        priority_queue<tlii, vector<tlii>, greater<tlii>> busy;

        for(int i = 0; i < n; i++) serverFree.push({servers[i], i});

        vector<int> ans(m);
        ll t = 0;
        for(int j = 0; j < m; j++) {
            t = max(t, (ll) j);
            while(!busy.empty() && get<0>(busy.top()) <= t) {
                auto [ft, w, idx] = busy.top(); busy.pop();
                serverFree.push({w, idx});
            }

            if(serverFree.empty()) {
                t = get<0>(busy.top());
                while(!busy.empty() && get<0>(busy.top()) <= t) {
                    auto [ft, w, idx] = busy.top(); busy.pop();
                    serverFree.push({w, idx});
                }
            }

            auto [w, idx] = serverFree.top(); serverFree.pop();
            ans[j] = idx;
            busy.push({t + tasks[j], w, idx});
        }
        return ans;
    }
};