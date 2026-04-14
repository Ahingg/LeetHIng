class Solution {
public:
    typedef long long ll;
    const ll INF = 1e15;

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<ll> flatten_f;
        for(auto& f:factory) {
            for(int i = 0; i < f[1]; i++){
                flatten_f.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = flatten_f.size();

        vector<ll> dp(m+1, 0);

        for(int i = 0; i < n; i++) {
            vector<ll> inner_dp(m+1, INF);
            for(int j = 0; j < m; j++) {
                inner_dp[j+1] = min(inner_dp[j], dp[j] + (abs(robot[i] - flatten_f[j])));
            }
            dp = inner_dp;
        }

        return dp[m];
    }
};