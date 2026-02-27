class Solution {
public:
    const static int MAX_N = 1e5;
    int parent[MAX_N+5];

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    int minOperations(string s, int k) {
        int n = s.length();
        int count = 0;
        for(char c: s) if(c == '0') count++;
        if(!count) return 0;

        queue<int> BFS;
        BFS.push(count);

        for(int i = 0; i < MAX_N + 5; i++) parent[i] = i;

        int distance[MAX_N+2];
        memset(distance, -1, sizeof(int)*(MAX_N+2));
        distance[count] = 0;
        parent[count] = count+2;

        while(!BFS.empty()){
            int size = BFS.size();
            for(int i = 0; i < size; i++){
                int x = BFS.front();
                // cout << "Step: " << x << endl;
                BFS.pop();

                if(!x) return distance[x];

                int iMin = max(0, k+x-n);
                int iMax = min(k, x);

                int xMin = k + x - 2*iMax;
                int xMax = k + x - 2*iMin;
                // cout << "Min max " << xMin << " " << xMax << endl;
                // 4 - 2 - 0,

                // find the node for MinimumX
                
                int curr = find(xMin);
                // check from the range xMin to xMax
                while(curr <= xMax){
                    distance[curr] = distance[x] + 1;
                    BFS.push(curr);

                    parent[curr] = curr + 2;
                    curr = find(curr);
                }

            }
        }
        return -1;
    }
};