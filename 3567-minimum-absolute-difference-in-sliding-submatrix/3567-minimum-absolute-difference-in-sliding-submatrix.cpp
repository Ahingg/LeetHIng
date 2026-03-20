class Solution {
public:
    const int INF = 1e7;
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));
        for(int i = 0; i + k <= m; i++){
            for(int j = 0; j + k <= n; j++) {
                vector<int> list;
                for(int x = i; x < i + k; x++){
                    for(int y = j; y < j + k; y++){
                        // cout << grid[x][y] << endl;
                        list.push_back(grid[x][y]);
                    }
                }
                sort(list.begin(), list.end());
                int minValue = INF;
                for(int x = 1; x < list.size(); x++){
                    // cout << a << " " << prevValue << endl;
                    if(list[x] != list[x-1]) minValue = min(minValue, list[x] - list[x-1]);
                }
                result[i][j] = (minValue == INF) ? 0 : minValue;
            }
        }

        return result;
    }
};