class Solution {
public:
    struct Node {
        int maxLen = 0, prefLen = 0, suffLen = 0, prefChar = 0, suffChar = 0, length = 0;
    };

    vector<Node> tree;
    int n;

    Node merge(const Node& L, const Node& R) {
        Node parent;
        parent.length = L.length + R.length;
        parent.prefChar = L.prefChar;
        parent.suffChar = R.suffChar;
        parent.maxLen = max(L.maxLen, R.maxLen);
        if(L.suffChar == R.prefChar) parent.maxLen = max(parent.maxLen, L.suffLen + R.prefLen);

        if(L.prefLen == L.length && L.prefChar == R.prefChar) parent.prefLen = L.length + R.prefLen; 
        else parent.prefLen = L.prefLen;

        if(R.suffLen == R.length && R.suffChar == L.suffChar) parent.suffLen = R.length + L.suffLen;
        else parent.suffLen = R.suffLen;
        
        return parent;
    }

    void build(const string& s, int node, int start, int end) {
        if(start == end) {
            tree[node] = {1,1,1,s[start], s[start], 1};
            return;
        }

        int mid = start + (end - start) / 2;
        build(s, 2*node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if(start == end) {
            tree[node] = {1,1,1, ch, ch, 1};
            return;
        }

        int mid = start + (end - start) / 2;
        if(idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        }
        else update(2 * node + 1, mid + 1, end, idx, ch);
        tree[node] = merge(tree[2 * node], tree[2*node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(s, 1, 0, n-1);

        vector<int> ans;
        ans.reserve(k);

        for(int i = 0; i < k; i++) {
            update(1, 0, n-1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};