class Solution {
public:
    typedef vector<vector<int>> vvi;
    const int MOD = 1e9+7;
    int dy[3] = {1, 0, 1};
    int dx[3] = {1, 1, 0};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = board.size();
        
        vvi cnt(n, vector<int>(n, 0));
        vvi score(n, vector<int>(n, -1));
        score[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;

        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--){ 
                if(board[i][j] == 'X' || (i == n - 1 && j == n-1)) continue;

                int curr = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                for(int d = 0; d < 3; d++) {
                    int nr = i + dy[d];
                    int nc = j + dx[d];
                    if(nr < 0 || nr > n-1 || nc < 0 || nc > n-1 || score[nr][nc] == -1) continue;
                    int point = score[nr][nc] + curr;
                    if(point > score[i][j]) {
                        score[i][j] = point;
                        cnt[i][j] = cnt[nr][nc];
                    }
                    else if(point == score[i][j]){
                        cnt[i][j] = (cnt[i][j] + cnt[nr][nc]) % MOD;
                    }
                } 
            }
        }

        if(score[0][0] == -1) return {0, 0};
        return {score[0][0], cnt[0][0]};
    }
};