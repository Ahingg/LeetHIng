class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int, int> odd, even;
        int n = nums.size();
        int maxLength = 0;
        for(int i = 0; i < n-1; i++){
            odd.clear(); even.clear();

            if(nums[i] & 1) odd[nums[i]]++;
            else even[nums[i]]++;

            for(int j = i+1; j < n; j++){
                if(nums[j] & 1) odd[nums[j]]++;
                else even[nums[j]]++;

                if(odd.size() == even.size()) maxLength = max(maxLength, j-i+1);
            }
        }

        return maxLength;
    }
};