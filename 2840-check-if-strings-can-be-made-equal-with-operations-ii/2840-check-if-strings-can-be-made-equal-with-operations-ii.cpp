class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> odd1(26, 0), even1(26, 0);
        vector<int> odd2(26, 0), even2(26, 0);

        const int n = s1.length();

        for(int i = 0; i < n; i++) {
            if(i & 1) {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
            else {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(odd1[i] != odd2[i]) return false;
            if(even1[i] != even2[i]) return false;
        } 
        return true;
    }
};