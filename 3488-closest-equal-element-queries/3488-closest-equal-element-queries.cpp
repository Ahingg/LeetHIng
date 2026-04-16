class Solution {
public:
    const int INF = 1e9;
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int qn = queries.size();
        int n = nums.size();
        
        unordered_map<int, vector<int>> list;
        vector<int> answer;
        for(int i = 0; i < n; i++){
            list[nums[i]].push_back(i);
        }

        for(auto q: queries) {
            auto& c = list[nums[q]];
            const int s = c.size();
            if(s == 1) {
                // if only 1 exists, no way to find the pair
                answer.push_back(-1);
                continue;
            }
                // querying front and back, which if query front, we take between the first index after and first index before.
            int result = INF;
            if(q == c[0]) {
  
                // if front, take c[s-1] and c[1]
                result = min(n - c[s-1] + c[0], c[1] - c[0]);
            }
            else if(q == c[s-1]){
                // if back, take c[0] and c[s-2];
                result = min(n - c[s-1] + c[0], c[s-1] - c[s-2]);
            }
            else {
                auto it = lower_bound(c.begin(), c.end(), q);
                int d = distance(c.begin(), it);
                // cout << c[d] << " " << c[d-1] << " " << c[d+1] << endl;
                result = min(c[d] - c[d-1], c[d+1] - c[d]);
            }

            answer.push_back(result);
        }

        return answer;
    }
};