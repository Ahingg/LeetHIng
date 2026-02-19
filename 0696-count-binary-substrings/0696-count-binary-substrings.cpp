class Solution {
public:
    int countBinarySubstrings(string s) {
        int count[2] = {0,0};
        count[s[0] - '0']++;
        int total = 0;
        for(int i = 1; i < s.length(); i++) {
            int x = s[i] - '0';
            if(s[i] == s[i-1]) count[x]++;
            else count[x] = 1; 
            if(count[!x] >= count[x]) total++;
        }
        return total;
    }
};