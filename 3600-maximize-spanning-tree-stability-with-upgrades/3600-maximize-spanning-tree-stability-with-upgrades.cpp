class Solution {
public:
    const static int MAX_N = 1e5;
    vector<int> parent, rank;

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool check(int i, int j){
        int root1 = find(i);
        int root2 = find(j);
        if(root1 != root2) {
            if(rank[root1] < rank[root2]) parent[root1] = parent[root2];
            else {
                parent[root2] = parent[root1];
                rank[root1]++;    
            }
            return true;
        }
        return false;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        int edge_count = 0;
        int min_str = 2e9;
        vector<vector<int>> upgd;
        for(auto& edge: edges){
            if(edge[3] == 1){
                if(!check(edge[0], edge[1])) return -1;
                edge_count++;
                min_str = min(min_str, edge[2]);
            }
            else upgd.push_back(edge);
        }

        sort(upgd.begin(), upgd.end(), [](const vector<int>& a, const vector<int>& b){return a[2] > b[2];});

        vector<int> final_upgd;
        for(auto& edge: upgd){
            if(check(edge[0], edge[1])){
                edge_count++;
                final_upgd.push_back(edge[2]);
            }
        }
        
        if(edge_count != n-1) return -1;

        int upgd_count = final_upgd.size();
        int result = min_str;
        if(upgd_count > 0){
            int upgraded = 2 * final_upgd.back();
            result = min(result, upgraded);

            if(upgd_count > k) {
                int last_after_k = final_upgd[upgd_count - k - 1];
                result = min(result, last_after_k);
            }
        }

        return result;

    }  
};