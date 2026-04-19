class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int j = 0;
        int result = 0;
        for(int i = 0; i < n; i++){
            while (j < m && nums1[i] <= nums2[j]) {
                j++;
            }
            result = max(j-i-1, result);
            if(j == m) break;
        }
        return result;
    }
};