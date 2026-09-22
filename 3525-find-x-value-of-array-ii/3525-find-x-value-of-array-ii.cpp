class Solution {
    typedef long long ll;

    struct Node {
        ll total = 1;
        std::vector<ll> pref;

        void init(int k) {
            pref.assign(k, 0);
            total = 1;
        }
    };

    class SegmentTree {
        int n, k;
        std::vector<Node> tree;

        void merge(const Node& L, const Node& R, Node& res) {
            res.total = (L.total * R.total) % k;
            for (int r = 0; r < k; r++) {
                res.pref[r] = L.pref[r];
            }
            for (int r = 0; r < k; r++) {
                if (R.pref[r] > 0) {
                    ll rem = (L.total * r) % k;
                    res.pref[rem] += R.pref[r];
                }
            }
        }

        void build(const std::vector<int>& nums, int node, int start, int end) {
            tree[node].init(k);
            if (start == end) {
                ll val = nums[start] % k;
                tree[node].total = val;
                tree[node].pref[val] = 1;
                return;
            }
            int mid = start + (end - start) / 2;
            build(nums, 2 * node, start, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            merge(tree[2 * node], tree[2 * node + 1], tree[node]);
        }

        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                std::fill(tree[node].pref.begin(), tree[node].pref.end(), 0);
                ll modVal = val % k;
                tree[node].total = modVal;
                tree[node].pref[modVal] = 1;
                return;
            }
            int mid = start + (end - start) / 2;
            if (idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            merge(tree[2 * node], tree[2 * node + 1], tree[node]);
        }

        void querySuffix(int node, int start, int end, int p, Node& acc, bool& is_first) {
            if (start >= p) {
                if (is_first) {
                    acc.total = tree[node].total;
                    acc.pref = tree[node].pref;
                    is_first = false;
                } else {
                    ll new_total = (acc.total * tree[node].total) % k;
                    std::vector<ll> next_pref = acc.pref;
                    for (int r = 0; r < k; r++) {
                        if (tree[node].pref[r] > 0) {
                            ll rem = (acc.total * r) % k;
                            next_pref[rem] += tree[node].pref[r];
                        }
                    }
                    acc.pref = std::move(next_pref);
                    acc.total = new_total;
                }
                return;
            }
            int mid = start + (end - start) / 2;
            if (p <= mid) {
                querySuffix(2 * node, start, mid, p, acc, is_first);
            }
            querySuffix(2 * node + 1, mid + 1, end, p, acc, is_first);
        }

    public:
        SegmentTree(const std::vector<int>& nums, int K) : k(K) {
            n = nums.size();
            tree.resize(4 * n);
            build(nums, 1, 0, n - 1);
        }

        void updateIndex(int idx, int val) {
            update(1, 0, n - 1, idx, val);
        }

        ll queryPrefixRemainder(int p, int target_x) {
            if (p < 0 || p >= n || target_x < 0 || target_x >= k) return 0;
            Node acc;
            acc.init(k);
            bool is_first = true;
            querySuffix(1, 0, n - 1, p, acc, is_first);
            return acc.pref[target_x];
        }
    };

public:
    std::vector<int> resultArray(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        SegmentTree st(nums, k);
        std::vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int p = q[2];
            int target_x = q[3];

            st.updateIndex(idx, val);
            ans.push_back((int)st.queryPrefixRemainder(p, target_x));
        }
        return ans;
    }
};