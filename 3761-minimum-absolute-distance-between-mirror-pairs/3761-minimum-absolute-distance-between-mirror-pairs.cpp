class Solution {
public:
    typedef long long ll;
    const ll INF = 1e15;
    ll reverse(int num) {
        // trail
        while(num%10 == 0) num /= 10;
        ll result = 0;
        while(num) {
            result = (result * 10) + (num%10);
            num /= 10;
        } 
        return result;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll, ll> rev_seen;
        ll result = INF;
        for(int i = 0; i < n; i++) {
            if(rev_seen[nums[i]] != 0) {
                result = min(result, i + 1 - rev_seen[nums[i]]);
            }
            ll reversed = reverse(nums[i]);
            // i+1 so we can distinguish between map's default value 0 with real index.
            rev_seen[reversed] = i+1;
        }

        return result == INF ? -1 : result;
    }
};