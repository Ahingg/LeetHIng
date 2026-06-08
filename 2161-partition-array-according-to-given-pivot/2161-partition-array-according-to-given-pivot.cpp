class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left;
        for(auto& x: nums) if(x < pivot) left.push_back(x);
        for(auto& x: nums) if(x == pivot) left.push_back(x);
        for(auto& x: nums) if(x > pivot) left.push_back(x);
        return left;
    }
};