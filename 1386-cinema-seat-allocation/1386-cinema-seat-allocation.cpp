class Solution {
public:
    typedef pair<int, int> pii;
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int, pii> loc;
        
        for(const auto& x: res) {
            int r = x[0], s = x[1];
            if(!loc.contains(r)){
                loc[r] = {2, 9};
            }
            if(s <= 5) {
                loc[r].first = max(loc[r].first, s + 1);
            }
            else {
                loc[r].second = min(loc[r].second, s - 1);
            }
            
        }
        int total = 0;
        for(const auto& [k, v]: loc) {
            // cout << k << " | " << v.first << " " << v.second << endl;
           if(v.first == 2 && v.second == 9) total+=2;
           else if(v.first <= 2 && v.second >= 5) total++;
           else if(v.first <= 4 && v.second >= 7) total++;
           else if(v.first <= 6 && v.second >= 9) total++;
           n--;
        }
        total += n * 2;

        return total;
    }
};