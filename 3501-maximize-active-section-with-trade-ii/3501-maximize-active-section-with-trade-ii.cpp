class Solution {
    struct SparseTable {
        vector<vector<int>> st;
        
        void build(const vector<int>& arr) {
            int n = arr.size();
            if (n == 0) return;
            int max_log = __lg(n) + 1;
            st.assign(max_log, vector<int>(n, 0));
            st[0] = arr;
            for (int k = 1; k < max_log; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int L, int R) {
            if (L > R) return 0;
            int k = __lg(R - L + 1);
            return max(st[k][L], st[k][R - (1 << k) + 1]);
        }
    };

    struct ZeroGroup {
        int start, end, len;
    };
    struct OneBlock {
        int start, end;
    };

    int get_eff_len(const ZeroGroup& z, int l, int r) {
        int start = max(z.start, l);
        int end = min(z.end, r);
        if (start <= end) return end - start + 1;
        return 0;
    }
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();

        // 1. Total 1s in the original string
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        // 2. Extract zero groups
        vector<ZeroGroup> zero_groups;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                int end = i - 1;
                zero_groups.push_back({start, end, end - start + 1});
            } else {
                i++;
            }
        }

        int m = zero_groups.size();

        if (m < 2) {
            return vector<int>(queries.size(), total_ones);
        }

        vector<OneBlock> one_blocks(m - 1);
        vector<int> W(m - 1);

        for (int i = 0; i < m - 1; i++) {
            one_blocks[i] = {zero_groups[i].end + 1, zero_groups[i + 1].start - 1};
            W[i] = zero_groups[i].len + zero_groups[i + 1].len;
        }

        SparseTable st;
        st.build(W);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            int i_first = -1;
            int low = 0, high = m - 2;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (one_blocks[mid].start >= l) {
                    i_first = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            int i_last = -1;
            low = 0; high = m - 2;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (one_blocks[mid].end <= r) {
                    i_last = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            int max_gain = 0;

            if (i_first != -1 && i_last != -1 && i_first <= i_last) {
                int len_l = get_eff_len(zero_groups[i_first], l, r);
                int len_r = get_eff_len(zero_groups[i_first + 1], l, r);
                if (len_l > 0 && len_r > 0) {
                    max_gain = max(max_gain, len_l + len_r);
                }

                if (i_last > i_first) {
                    len_l = get_eff_len(zero_groups[i_last], l, r);
                    len_r = get_eff_len(zero_groups[i_last + 1], l, r);
                    if (len_l > 0 && len_r > 0) {
                        max_gain = max(max_gain, len_l + len_r);
                    }
                }

                if (i_first + 1 <= i_last - 1) {
                    max_gain = max(max_gain, st.query(i_first + 1, i_last - 1));
                }
            }

            ans.push_back(total_ones + max_gain);
        }

        return ans;
        
    }
};