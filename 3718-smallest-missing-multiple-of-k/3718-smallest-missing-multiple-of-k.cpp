class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> l(101, false);
        for(const int& x: nums) l[x] = true;
        for(int i = k; ; i += k) if(i > 100 || !l[i]) return i;
        return -1;
    }
};