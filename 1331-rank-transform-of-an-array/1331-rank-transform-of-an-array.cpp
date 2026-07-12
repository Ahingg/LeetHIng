class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<int> ans = arr;
        
        sort(arr.begin(), arr.end());
        int currRank = 1;
        unordered_map<int, int> rank;
        rank[arr[0]] = currRank;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i-1]) continue;
            currRank++;
            rank[arr[i]] = currRank;
        }

        for(int i = 0; i < n; i++) {
            ans[i] = rank[ans[i]];
        }

        return ans;
    }
};