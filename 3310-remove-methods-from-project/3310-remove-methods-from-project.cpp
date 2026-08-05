class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> E(n+1);

        for(const auto& x: invocations) {
            E[x[0]].push_back(x[1]);
        }

        queue<int> q;
        q.push(k);
        vector<bool> infected(n, false);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(infected[curr]) continue;
            infected[curr] = true;
            for(const int e: E[curr]) {
                q.push(e);
            }
        }
        bool viable = true;
        for(const auto& x: invocations) {
            if(!infected[x[0]] && infected[x[1]]) viable = false;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(viable && infected[i]) continue;
            ans.push_back(i);
        }

        return ans;
    
    }
};