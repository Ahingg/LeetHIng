class Solution {
public:
    typedef long long ll;
    ll maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        // arr[0, 2, ... 2i], i from 0 to n/2
        // arr[1, 3, ... 2i+1] i from 0 to n/2
        vector<ll> nums(n, 0);
        // convert every value to its square
        for(int i = 0; i < n; i++) nums[i] = arr[i] * arr[i];

        // sort ascending or descendingly, so we can choose which belongs to the first which belong to the second
        sort(nums.begin(), nums.end(), greater<ll>());
        int l = 0, r = n-1;
        ll ans = 0;
        while(l < r) {
            ans += nums[l];
            ans -= nums[r];
            l++; r--;
        }

        if(l == r) ans += nums[l];
        return ans;
    }
};

