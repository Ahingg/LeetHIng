class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxList(n, 0), minList(n, 0);
        maxList[0] = nums[0]; minList[n-1] = nums[n-1];
        int i = 1;

        while(i < n) {
            int j = n - i - 1;
            maxList[i] = max(maxList[i-1], nums[i]);
            minList[j] = min(minList[j+1], nums[j]);
            i++;
        }
        // for(const auto& x: maxList) cout << x << " ";
        // cout << endl;
        // for(const auto& x: minList) cout << x << " ";

        int ans = -1;
        for(int i = 0; i < n; i++) {
            int score = maxList[i] - minList[i];
            if(score <= k) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};