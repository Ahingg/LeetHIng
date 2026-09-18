class Solution {
public:
    typedef pair<int, int> pii;
    vector<string> maxNumOfSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len = s.length();
        // simpen minimal sama maximal index dari setiap abjad
        // kita coba ambil dari setiap abjad
        vector<vector<int>> ranges(26, vector<int>(2, -1));
        for(int i = 0; i < len; i++) {
            int idx = s[i] - 'a';

            if(ranges[idx][0] == -1) {
                ranges[idx][0] = i;
            }
            ranges[idx][1] = i;
        }
        // setiap range abjad bakal coba nge expand range mereka ke setiap possible abjad yang lain
        // time complexity bakal ngambil 26 kali untuk setiap abjad, jadi as simple as 26^2
        // overlap jika: a (start, end) dan b(start, end)
        // a.start >= b.end or b.start >= a.end
        vector<pii> candidates;
        for(int i = 0; i < 26; i++) {
            if(ranges[i][0] == -1) continue;
            int l = ranges[i][0], r = ranges[i][1];
            bool valid = true;
            for(int j = l; j <= r; j++) {
                int idx = s[j] - 'a';
                if(ranges[idx][0] < l) {
                    valid = false;
                    break;
                }
                
                r = max(r, ranges[idx][1]);
                
            }
            if(valid) candidates.push_back({l, r});
        }

        sort(candidates.begin(), candidates.end(), [](const pii& a, const pii& b) {
            return a.second < b.second;
        });
        // for(const auto& [l, r]: candidates) cout << l << " " << r << endl;

        // untuk list hasilnya, at most akan ada 26^2 list, jadi untuk di sort akan lumayan cepat. Sort via custom sorting lewat len.
        
        // sekarang tinggal tentuin apakah akan overlap kalau masukin 1 range ke list yang udah ada sekarang
        // jika ada satu range l,r maka cek apakah l atau r ada didalam range setiap list tersebut.
        // vector<pii> ans;

        // for(int i = 0; i < candidates.size(); i++) {
        //     const auto [l, r] = candidates[i];
        //     cout << l << " " << r << endl;
        //     bool found = true;
        //     for(const auto& [l2, r2]: ans) {
        //         if((l >= l2 && l <= r2) || (r >= l2 && r <= r2) || (l2 >= l && l2 <= r) || (r2 >= l && r2 <= r)) {
        //             found = false;
        //             break;
        //         }
        //     }
        //     if(found) {
        //         ans.push_back({l, r});
        //         // cout << l << " " << r << endl;
        //     }
        // } 

        vector<string> f;
        int last = -1;
        for(const auto& [l, r]: candidates) {
            if(l > last) {
                f.push_back(s.substr(l, (r-l+1)));
                last = r;
            }
                
        }
        return f;
    }
};