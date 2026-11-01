class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 1 2 3 4 5 6
        // 2 2 4 6 8 9
        // 9 9 9 11 13 15 -- 7
        // 15 15 15 15 17 19 -- 6
        // 19 19 19 19 19 21 -- 4
        // 21 21 21 21 21 21 -- 2
        int n = nums.size();
        int minVal = *min_element(nums.begin(), nums.end());
        int ans = 0; 
        for(int i = 0; i < n; i++) {
            ans += (nums[i] - minVal);
        }
        return ans;
        
    }
};