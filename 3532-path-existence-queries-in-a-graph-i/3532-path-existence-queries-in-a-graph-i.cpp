class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int qn = queries.size();
        
        vector<int> parent;
        for(int i = 0; i < n; i++) parent.push_back(i);
        int upper = nums[0] + maxDiff;
        int currP = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] + maxDiff < nums[i]) {
                currP = i;
                upper = nums[i] + maxDiff;
                continue;
            }
            upper = nums[i] + maxDiff;
            parent[i] = currP;
        }
        vector<bool> ans;
        for(const auto& q: queries) ans.push_back(parent[q[0]] == parent[q[1]]);
        return ans;
    }
};