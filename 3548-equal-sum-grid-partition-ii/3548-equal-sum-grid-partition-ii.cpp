class Solution {
public:
        // if 1 row, only vertical cuts can be made, thus there cannot be any cell discounted as it will disconnect the section.

        // Same thing apply on 1 column, only horizontal cut can be done. Thus there cannot be any discounted cell.

        // Similar thing would also happen on the cut that left out only section with one row or one column

        // (only exception is for the first and the last part of the cut perpendicular to the current cut.)
        
        // the flow is we need to check like the usual thing without any cuts. 
        // check if currSum*2 == total or arr[total- currSum*2] on that scope of (i,j) where i, j

        // for the hash array, we need to create an array of hash table ig. (which can possibly bottleneck the memory)

    typedef long long ll;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> sumH(m, 0), sumV(n, 0);
        unordered_map<ll, int> listH, listV, list1, list2;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                listH[grid[i][j]]++;
                list1[grid[i][j]]++;
                sumH[i] += grid[i][j];
                sumV[j] += grid[i][j];
                if(i == m-1 && j > 0) {
                    sumV[j] += sumV[j-1];
                }
            }
            if(i > 0) sumH[i] += sumH[i-1];
        }
        
        ll total = sumH[m-1];
        // if m == 1
        if(m == 1) {
            if(n == 2) return grid[0][0] == grid[0][1];
            for(int i = 0; i < n-1; i++) {
                // sumV[i] should be check whether == total if * 2 or not
                if(sumV[i] * 2 == total) return true;
                // if not, try to exclude the first element and the i element
                if((sumV[i] * 2) == total + grid[0][0] || ((sumV[i]*2) == total + grid[0][i])) return true;
                // try to exclude the i + 1 element and n-1 element
                ll otherPart = total - sumV[i];
                if((otherPart - grid[0][i+1]) == sumV[i] || (otherPart - grid[0][n-1]) == sumV[i]) return true;
            }
            return false;
        }
        // if n == 1
        if(n == 1) {
            if(m == 2) return grid[0][0] == grid[1][0];
            for(int i = 0; i < m-1; i++) {
                if(sumH[i] * 2 == total) return true;
                if((sumH[i] * 2) == total + grid[0][0] || ((sumH[i]*2) == total + grid[i][0])) return true; 
                ll otherPart = total - sumH[i];
                if((otherPart - grid[i+1][0]) == sumH[i] || (otherPart - grid[m-1][0] == sumH[i])) return true;
            }
            return false;
        }

        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < n; j++){
                listV[grid[i][j]]++;
                if(--listH[grid[i][j]] == 0) listH.erase(grid[i][j]); 
            }
            ll x = sumH[i] * 2;
            if(x == total) return true;
            if(x > total) {
                if(i == 0) {
                    if(x == total + grid[i][0] || x == total + grid[i][n-1]) return true;
                }
                else {
                    if(listV[x - total] > 0) return true;
                }
                continue;
                // other part is smaller
                // so if sumH[i]*2 - otherPart exists in the array, true
            }
            if(x < total) {
                if(i == m-2) {
                    if(x == total - grid[i+1][0] || x == total - grid[i+1][n-1]) return true;
                    continue;
                }
                ll remainder = total-x;
                if(listH[remainder] > 0) return true;
            }
        }
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                list2[grid[j][i]]++;
                if(--list1[grid[j][i]] == 0) list1.erase(grid[j][i]); 
            }
            ll x = sumV[i] * 2;
            if(x == total) return true;
            if(x > total) {
                if(i == 0) {
                    if((x == (total + grid[0][0])) || (x == (total + grid[m-1][0]))) return true;
                }
                else {
                    if(list2[x - total] > 0) return true;
                }

                // other part is smaller
                // so if sumH[i]*2 - otherPart exists in the array, true
                continue;
            }
            if(x < total) {
                if(i == n-2) {
                    if((x == total - grid[0][i+1]) || x == total - grid[m-1][i+1]) return true;
                    continue;
                }
                ll remainder = total - x;
                // cout << x << endl;
                // cout << total << endl;
                if(list1[remainder] > 0) return true;
            }
        }
        return false;
    }
};