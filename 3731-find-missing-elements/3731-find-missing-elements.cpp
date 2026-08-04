class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        vector<bool> occ(101, false);
        int mini = 101, maxi = -1;
        for(int i = 0; i < n; i++) {
            occ[nums[i]] = true;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        vector<int> result;
        for(int i = mini; i <= maxi; i++) if(!occ[i]) result.push_back(i);
        return result; 
    }
};