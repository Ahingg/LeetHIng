class Solution {
public:

    bool buildPes(vector<int>& tab, const string& target, int from, string& res) {
        char firstC = target[from] + 1;
        while(firstC <= 'z' && tab[firstC - 'a'] == 0) {
        // cout << firstC << " " << tab[firstC - 'a'] << endl;
            firstC++;
        }
        // cout << endl;
        if(firstC > 'z') return false;
        res += firstC;
        tab[firstC - 'a']--;
        for(int i = 0; i < 26; i++) {
            if(!tab[i]) continue;
            for(int j = 0; j < tab[i]; j++) {
                res += ('a' + i);
            }
            tab[i] = 0;
        }
        return true;
    }
    string lexGreaterPermutation(string s, string target) {
        int len = s.length();
        vector<int> tab(26, 0);
        for(const char& c: s) tab[c - 'a']++;


        // approach 2 way
        // jadi kita bakal pake 2 sistem, optimis dan pessimist
        // kita bakal mulai dari sistem optimis kalau misalnya: huruf pertama target ada di string source
        // otherwise, pasti kita cuma bisa cari yang paling kecil diatas huruf pertama target
        // bool optimist = true;
        string res = "";
        for(int i = 0; i < len; i++) {

            // if exist maka path optimis masih ada
            int idx = target[i] - 'a';
            if(tab[idx]) {
                res += target[i];
                tab[idx]--;
            }
            else {
                bool test = buildPes(tab, target, i, res);
                // cout << res << endl;
                if(test) return res;
                break;
            }
        }
        if(res > target && res.length() == len) return res;
        // berarti kita harus bongkar ulang dari belakang.
        int i = res.length() - 1;
        // bongkar satu per satu
        while(i >= 0) {
            tab[res[i] - 'a']++;
            res.pop_back();

            bool test = buildPes(tab, target, i, res);
            if(test) return res;
            i--;
        }
        return res;

    }
};