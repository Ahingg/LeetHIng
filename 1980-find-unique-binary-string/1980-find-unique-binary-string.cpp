class Solution {
public:
    unordered_set<string> check;
    string simulate(int n, string x){
        if(n == 0) {
            if(check.count(x)) return "";
            return x;
        }

        string left = simulate(n-1, x + '0');
        if(left != "") return left;
        string right = simulate(n-1, x + '1');
        return right;
 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(string x: nums) check.insert(x);
        return simulate(nums[0].length(), "");
    }
};