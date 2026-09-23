class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // pertama ngecek prefix sama suffix sumnya dlu, kalo streak 1 ada yang lanhgsung bisa di take atau ga
        // apakah kalo misalnya gw pilih greedy akan selalu berhasil?
        // atau ga gini aja brok, gw ambil suffix sumnya, trus gw cek ada yang prefix sumnya sampe ga, kalau misalnya ada, langsung take into candidate answer, itung min(ans, totalSize)

        int n = nums.size();
        int total = 0;
        for(const int& v: nums) total += v;
        int target = total - x;


        int maxLen = -1;
        int i = 0, j = 0;
        int currSum = 0;
        // cout << target << endl;
        while(i < n && j < n) {
            currSum += nums[j];
            if(currSum == target) maxLen = max(maxLen, j - i + 1);
            while(i < n && currSum > target) {
                currSum -= nums[i];
                i++;
            }
            if(currSum == target) maxLen = max(maxLen, j - i + 1);
            // if(currSum == target) minLen = min(minLen, j - i + 1);
            j++;
        }
        
        return maxLen == -1 ? maxLen : n - maxLen;
    }
};