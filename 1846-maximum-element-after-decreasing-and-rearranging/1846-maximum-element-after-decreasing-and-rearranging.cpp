class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1, 0);
        for(const auto& x: arr) freq[min(x, n)]++;

        int highest = 0;
        for(int i = 1; i <= n; i++) {
            if(!freq[i]) continue;
            if(i > highest) {
                int step = i - highest;
                highest += min(step, freq[i]);
            }
        }

        // cout << highest << endl;
        return highest;
    }
};