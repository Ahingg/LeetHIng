class Solution {
public:

    stack<char> op;
    vector<vector<string>> st;

    void resolve() {
        int x = st.size() - 2, y  = st.size() - 1;
        if(op.top() == '+') {
            st[x].reserve(st[x].size() + st[y].size());
            st[x].insert(st[x].end(), st[y].begin(), st[y].end());
        }
        else {
            vector<string> res;
            res.reserve(st[x].size() * st[y].size());
            for(const auto& l: st[x]) {
                for(const auto& r: st[y]) {
                    res.push_back(l+r);
                }
            }
            st[x] = std::move(res);
        }
        op.pop();
        st.pop_back();
    }
    vector<string> braceExpansionII(string es) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // step 1, evaluasi setiap {}
        int n = es.size();

        char prev = '0', curr;

        for(int i = 0; i < n; i++) {
            curr = es[i];
            if(curr == ',') {
                while(!op.empty() && op.top() != '{') resolve();
                op.push('+');
            }
            else if(curr ==  '{') {
                if(prev == '}' || isalpha(prev)) op.push('*');
                op.push('{');   
            }
            else if(curr == '}') {
                while(!op.empty() && op.top() != '{') resolve();
                op.pop();
            }
            else {
                if(prev == '}') op.push('*');
                string s;
                for(; i < n && isalpha(es[i]); i++) s+= es[i];
                st.push_back({s});
                i--;
                curr = es[i];
            }
            prev = curr;
        }

        while(!op.empty()) resolve();

        auto ans = st.front();

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};