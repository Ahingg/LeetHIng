class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51);
        for(int i = 0; i < n; i++) freq[nums[i]]++;

        if(k == 1) {
            int maxVal = -1;
            for(int i = 1; i <= 50; i++) {
                if(i > maxVal && freq[i] == 1) maxVal = i;
            }
            return maxVal;
        }
        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if(nums[0] == nums[n-1]) return -1;
        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) return max(nums[0], nums[n-1]);
        if(freq[nums[0]] == 1) return nums[0];
        if(freq[nums[n-1]] == 1) return nums[n-1];
        return -1; 
        
    }
};