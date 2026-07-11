class Solution {
public:
    vector<int> parent;
    vector<int> vertexCnt;
    vector<int> edgeCnt;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int a, int b, int& comp) {
        int u = find(a);
        int v = find(b);
        
        if(u != v){
            if(u > v) swap(u,v);
            parent[v] = u;
            vertexCnt[u] += vertexCnt[v];
            edgeCnt[u] += edgeCnt[v] + 1;
            comp--;
        }
        else {
            edgeCnt[u]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) parent.push_back(i);
        vertexCnt.resize(n, 1);
        edgeCnt.resize(n, 0);

        int comp = n;
        for(const auto& e: edges){
            merge(e[0], e[1], comp);
        }
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) {
                int vertex = vertexCnt[i];
                int edge = edgeCnt[i];
                int actual = (vertex * (vertex-1)) / 2;
                if(edge != actual) comp--;
            }
        }
        return comp;
    }
};