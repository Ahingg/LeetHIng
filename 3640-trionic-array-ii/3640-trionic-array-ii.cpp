class Solution {
public:
    typedef long long ll;
    const ll MINF = -1e15;
    static const ll MAXN = 1e5;


    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        ll dp0[MAXN+5]; ll dp1[MAXN+5]; ll dp2[MAXN+5]; ll dp3[MAXN+5];
        for(int i = 0; i < n; i++){
            dp0[i] = 0;
            dp1[i] = MINF;
            dp2[i] = MINF;
            dp3[i] = MINF;
        }
        dp0[0] = nums[0];
        ll maxV = MINF;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                dp1[i] = max(dp1[i-1] + nums[i], dp0[i-1] + nums[i]);
                dp3[i] = max(dp3[i-1] + nums[i], dp2[i-1] + nums[i]);
                dp0[i] = max(dp0[i-1] + nums[i], (ll)nums[i]); 
                maxV = max(dp3[i], maxV);
            } 
            else if(nums[i] == nums[i-1]) {
                dp0[i] = nums[i];
            }
            else {
                dp2[i] = max(dp2[i-1] + nums[i], dp1[i-1] + nums[i]);
                dp0[i] = nums[i];
            }
            // printf("%lld %lld %lld %lld\n", dp0[i], dp1[i], dp2[i], dp3[i]);
        }
        
        return maxV;
    }
};