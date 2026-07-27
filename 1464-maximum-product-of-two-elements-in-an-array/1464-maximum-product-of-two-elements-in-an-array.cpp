class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = -1, b = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int num = nums[i] - 1;
            if(num > a) {
                b = a;
                a = num;
            }
            else if(num > b){
                b = num;
            }
        }
        return (a*b);
    }
};