class Solution {
public:
    const int INF = 1e9;
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // pake 2 kali sliding window.
        
        // kiri ke kanan
        vector<int> leftPass(n + 1, INF);
        int curr = 0;
        int l = 0, r = 0;
        while(r < n) {
            int len = INF;
            curr += arr[r];
            while(curr > target) {
                curr -= arr[l];
                l++;
            }
            if(curr == target) len = r-l+1;
            if(r > 0) leftPass[r] = min(len, leftPass[r-1]);
            else leftPass[r] = len;
            r++;
        }

        vector<int> rightPass(n+1, INF);
        curr = 0;
        l = n-1, r = n-1;
        while(l >= 0) {
            int len = INF;
            curr += arr[l];
            while(curr > target) {
                curr -= arr[r];
                r--;
            }
            if(curr == target) len = r-l+1;
            if(r < n-1) rightPass[l] = min(len, rightPass[l+1]);
            else rightPass[l] = len;
            l--;
        }

        // for(int i = 0; i < n; i++) {
        //     cout << leftPass[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; i++) {
        //     cout << rightPass[i] << " ";
        // }
        // cout << endl;
        
        int ans = INF;
        for(int i = 0; i < n-1; i++) {
            ans = min(leftPass[i] + rightPass[i+1], ans);
        }
        return (ans == INF) ? -1 : ans; 
    }
};