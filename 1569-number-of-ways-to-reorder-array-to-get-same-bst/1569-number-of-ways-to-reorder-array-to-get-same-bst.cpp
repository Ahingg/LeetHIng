class Solution {
public:
    typedef long long ll;
    static const ll MOD = 1e9+7;
    vector<vector<ll>> C;
    ll dfs(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 1;
        vector<int> L, R;
        for(int i = 1; i < n; i++) {
            (arr[i] < arr[0] ? L : R).push_back(arr[i]);
        }

        return C[n-1][L.size()] * dfs(L) % MOD * dfs(R) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C.assign(n+1, vector<ll>(n+1, 0));
        for(int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};