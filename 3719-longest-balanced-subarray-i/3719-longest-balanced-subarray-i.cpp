class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> odd;
            unordered_map<int, int> even;

            for(int j = i; j < n; j++){
                auto& target = (nums[j] & 1) ? odd : even;
                target[nums[j]]++;

                if(odd.size() == even.size()) maxLength = max(maxLength, j-i+1);
            }

        }

        return maxLength;
    }
};