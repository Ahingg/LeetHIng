class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int size = nums.size();
        if(nums[1] <= nums[0]) return false;

        // if peak even then its increasing mode
        // if peak odd then its decreasing mode
        // peak more than 2 then false
        int count = 0;
        for(int i = 1; i < size; i++){
            if(nums[i] == nums[i-1]) return false;
            if((nums[i] < nums[i-1] && count % 2 == 0) || (nums[i] > nums[i-1] && count % 2 == 1)) count++;
            if(count > 2) return false;
        }
        if(count < 2) return false;
        return true;
    }
};