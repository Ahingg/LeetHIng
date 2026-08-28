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

    string makePalindrome(const string& left, char midChar) {
        string full = left;
        if(midChar != 0) full += midChar;
        string right = left;
        reverse(right.begin(), right.end());
        full += right;
        return full;
    }

    string lexPalindromicPermutation(string s, string target) {
        int len = s.length();
        vector<int> tab(26, 0);
        for(const char& c: s) tab[c - 'a']++;
        // validasi kalau cuma ada maksimal 1 
        int oddCount = 0;
        char midChar = 0;
        for(int i = 0; i < 26; i++) {
            if(tab[i] & 1) {
                oddCount++;
                midChar = 'a' + i; 
            }
        }
        if(oddCount > 1) return "";


        vector<int> halfTab(26, 0);
        int halfLen = len / 2;
        for (int i = 0; i < 26; i++) {
            halfTab[i] = tab[i] / 2;
        }

        // sama kayak kemarin, cuma yang ini palindrome
        string res = "";
        for(int i = 0; i < halfLen; i++) {

            // if exist maka path optimis masih ada
            int idx = target[i] - 'a';
            if(halfTab[idx]) {
                res += target[i];
                halfTab[idx]--;
            }
            else {
                bool test = buildPes(halfTab, target, i, res);
                // cout << res << endl;
                if(test) return makePalindrome(res, midChar);
                break;
            }
        }
        if((int)res.length() == halfLen) {
            string full = makePalindrome(res, midChar);
            if(full > target) return full;
        }
        // berarti kita harus bongkar ulang dari belakang.
        int i = (int)res.length() - 1;
        // bongkar satu per satu
        while(i >= 0) {
            halfTab[res[i] - 'a']++;
            res.pop_back();

            bool test = buildPes(halfTab, target, i, res);
            if(test) return makePalindrome(res, midChar);
            i--;
        }
        return res;

    }
};
