class Solution {
public:
    typedef long long ll;
    ll countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<ll, ll>> dq;
        ll sumM = 0, sumNums = 0, ans = 0;
        int r = n - 1;

        for(int l = n-1; l >= 0; l--) {
            ll v = nums[l], c = 1;
            while(!dq.empty() && dq.front().first <= v) {
                sumM += (v - dq.front().first) * dq.front().second;
                c += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({v, c});
            sumM += v;
            sumNums += v;

            while(sumM - sumNums > k) {
                sumM -= dq.back().first;
                sumNums -= nums[r];
                if(--dq.back().second == 0) dq.pop_back();
                r--;
            }
            ans += r - l + 1;
        }

        return ans;
    }
};