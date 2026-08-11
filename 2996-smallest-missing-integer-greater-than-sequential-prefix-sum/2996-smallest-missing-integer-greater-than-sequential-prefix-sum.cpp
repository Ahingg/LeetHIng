class Solution {
public:

    // int getSum(int start, int end) {

    // }
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exist(51, false);
        // exist[nums[0]] = true;
        for(int i = 0; i < n; i++) {
            exist[nums[i]] = true;
        }

        int sum = nums[0];
        int i = 1;
        while(i < n) {
            if(nums[i-1] + 1 != nums[i]) {
                int gap = (nums[0] - 1) * i;
                int s  = (i * (i+1))/2;
                sum = s + gap;
                break;
            }
            i++;
            if(i == n) {
                int gap = (nums[0] - 1) * i;
                int s  = (i * (i+1))/2;
                sum = s + gap;
                break;
            }
        }

        while(sum <= 50 && exist[sum]) {
            sum++;
        }
        return sum;

        // int idx = 0;
        
        // pair<int, int> x = {-1, -2};
        // exist[nums[0]] = true;
        // for(int i = 1; i < n; i++) {
        //     // if(nums[i] == nums[i-1] + 1) chain++;
        //     exist[nums[i]] = true;
        //     if(nums[i] != nums[i-1] + 1) {
        //         if(i - idx - 1 > x.second - x.first) {
        //             // cout << i - idx << " " << x.second - x.first << endl;
        //             x = {idx, i - 1};
        //         }
        //         idx = i;
        //     }
        // }
        // if(n - 1 - idx > x.second - x.first) x = {idx, n-1};
        // cout << x.first << " " << x.second << endl;
        // int len = x.second - x.first + 1;
        // int gap = (nums[x.first] - 1) * len;
        // int s = (len * (len + 1))/2;
        // int suspect = s + gap;
        // while(suspect <= 50 && exist[suspect]) suspect++;
        
        // return suspect;
    }
};