class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> right(n,0);
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j]) {
                    right[i] = count;
                    break;
                }
                count++;
            }
        }

        int swapCount = 0;
        for(int i = 0; i < n; i++){
            int target = n-i-1;
            int j = i;
            while(j < n && right[j] < target){
                j++;
            }
            if(n == 2 && j == n) break;
            if(j == n) return -1;

            while(j > i){
                int temp = right[j];
                right[j] = right[j-1];
                right[j-1] = temp;

                swapCount++;
                j--;
            }
        }
        return swapCount;
    }
};