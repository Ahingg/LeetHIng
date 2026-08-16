class Solution {
public:
    bool stoneGameIX(vector<int>& nums) {
        int n = nums.size();
        int freq[3] = {0,0,0};
        for(int i = 0; i < n; i++) freq[nums[i]%3]++;
        if(freq[0] & 1) {
            return abs(freq[1] - freq[2]) >= 3;
        }
        return min(freq[1], freq[2]) >= 1;
    }
};