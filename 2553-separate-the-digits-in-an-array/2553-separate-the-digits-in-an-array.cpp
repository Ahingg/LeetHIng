class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            string x = to_string(nums[i]);
            for(auto c: x) res.push_back(c - '0');
        }
        return res;
    }
};