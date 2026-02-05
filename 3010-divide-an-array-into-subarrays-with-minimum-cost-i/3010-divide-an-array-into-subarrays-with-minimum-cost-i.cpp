class Solution {
public:
    const int INF = 1e9;
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = INF, second = INF;
        for(int i = 1; i < n; i++){
            if(nums[i] < first) {
                second = first;
                first = nums[i];
            }
            else if(nums[i] >= first && nums[i] < second) second = nums[i];
        }
        return nums[0] + first+second;
    }
};