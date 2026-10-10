class Solution {
public:
    typedef long long ll;
    ll minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxDiff = -1;
        vector<int> diff(n);
        
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }
        // as diff only could be at most 0 vs 10^5 which is 10^5, the size of O(n) can be achieved
        vector<int> mapping(maxDiff+5);
        for(int x: diff) mapping[x]++;
        ll k = k1 + k2;
        for(int i = maxDiff; i > 0; i--) {
            int take = min(1LL * mapping[i], k);
            k -= take;
            mapping[i] -= take;
            mapping[i-1] += take;
            if(k <= 0) break;
        }

        ll ans = 0;
        for(int i = 0; i <= maxDiff; i++) {
            ans += 1LL * mapping[i] * i * i;
        }
        return ans;
    }
};