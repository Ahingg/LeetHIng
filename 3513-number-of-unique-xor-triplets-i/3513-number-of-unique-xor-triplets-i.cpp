class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int c = 1;
        while(n) {
            n >>= 1;
            c *= 2;
        }
        return c;
    }
};
//[3 1 2 4 5]
// 3 1 2
// 3 3 3
// 3 1 1
// 3 1 2
// 