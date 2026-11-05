class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        int ans = 0;
        
        for(const auto x: arr1) {
            for(const auto y: arr2) {
                if(abs(x - y) <= d) goto end;
            }
            ans++;
            end:
        }
        return ans;
    }
};