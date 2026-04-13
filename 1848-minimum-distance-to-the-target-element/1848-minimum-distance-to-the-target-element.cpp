class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        if(nums[start] == target) return 0;
        int result = 1e9;
        int i = start+1;
        while(i < n){
            if(nums[i] == target) {
                result = i - start;
                break;
            }
            i++;
        }

        i = start-1;
        while(i >= 0){
            if(nums[i] == target && start - i < result) {
                result = start-i;
                break;
            }
            i--;
        }
        return result;
    }
};