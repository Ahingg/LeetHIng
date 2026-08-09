class Solution {
public:

    int memo[101][101];
    vector<int> suff;
    int n;

    int dfs(int i, int M){
        if(i + 2 * M >= n) return suff[i];
        if(memo[i][M] != 0) return memo[i][M];

        int m = 0;
        for(int x = 1; x <= 2*M; x++) {
            int score2 = dfs(i + x, max(M, x));
            m = max(m, suff[i] - score2);
        }
        return memo[i][M] = m;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suff.assign(n+1, 0);

        for(int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + piles[i];
        return dfs(0, 1);
    }
};