class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int largest = n - 1;

        vector<int> occ(202, 0);
        for(int i = 0; i < n; i++) {
            occ[nums[i]]++;
        }
        for(int i = 1; i < largest; i++) {
            if(occ[i] != 1) return false; 
        }
        if(occ[largest] != 2)  return false;
        return true;
    }
};