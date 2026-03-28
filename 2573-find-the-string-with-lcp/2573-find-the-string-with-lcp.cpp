class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s = "";
        int count = 0;
        vector<int>parent(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(parent[i] != -1) continue;
            if(++count > 26) return "";
            for(int j = 0; j < n; j++){
                if(lcp[i][j]) parent[j] += count; 
            }

        }
        // for(auto x: parent) cout << x << " ";

        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n - i) return "";
            for(int j = i+1; j < n; j++){
                int x = lcp[i][j];
                if(x != lcp[j][i]) return "";
                int x2 = (j < n - 1) ? lcp[i+1][j+1] : 0;
                x2 = (parent[i] == parent[j]) ? x2 + 1 : 0;
                if(x != x2) 
                {
                    return "";
                }
                
            }
        }
        for(int i = 0; i < n; i++){
            char e = 'a' + parent[i];
            s += e;
        }

        return s;
    }
};