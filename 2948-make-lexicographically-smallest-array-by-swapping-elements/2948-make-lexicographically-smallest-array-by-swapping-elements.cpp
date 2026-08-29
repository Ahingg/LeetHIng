class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pii> vp;
        for(int i = 0; i < n; i++) vp.push_back({nums[i], i});

        sort(vp.begin(), vp.end());
        vector<int> ans(n);

        int i = 0;
        while(i < n) {
            int j = i;
            vector<int> temp;

            while(j < n && (j == i || vp[j].first - vp[j-1].first <= limit)){
                temp.push_back(vp[j].second);
                j++;
            }

            sort(temp.begin(), temp.end());

            for(int k = 0; k < temp.size(); k++) {
                ans[temp[k]] = vp[i+k].first;
            }
            i = j;

        }
        return ans;

    }
};