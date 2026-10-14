class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i = 0; i < num; i++) {
            int pick = min(9, sum);
            ans += ('0' + pick);
            sum -= pick;
        }
        if(sum != 0) return "";
        return ans;
    }
};