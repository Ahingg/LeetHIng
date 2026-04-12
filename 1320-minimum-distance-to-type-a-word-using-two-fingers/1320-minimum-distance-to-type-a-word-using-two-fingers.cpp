class Solution {
public:

    int dist(int a, int b){
        if(a == 26) return 0;
        int row1 = a / 6, col1 = a%6;
        int row2 = b / 6, col2 = b%6;
        return abs(row1-row2) + abs(col1 - col2);
    }
    int minimumDistance(string word) {
        int n = word.length();

        vector<int> dp(27, 0);

        for(int i = 0; i < n - 1; i++){
            vector<int> dp_next(27, 1e9);
            int cur = word[i] - 'A';
            int next = word[i+1] - 'A';

            for(int j = 0; j < 27; j++) {
                if(dp[j] == 1e9) continue;
                dp_next[j] = min(dp_next[j], dp[j] + dist(cur, next));
                dp_next[cur] = min(dp_next[cur], dp[j] + dist(j, next));
            }
            dp = dp_next;
        }

        return *min_element(dp.begin(), dp.end());
    }
};