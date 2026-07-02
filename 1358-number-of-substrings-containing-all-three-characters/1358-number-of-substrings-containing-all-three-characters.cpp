class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int l = 0;
        int counter[3] = {0,0,0};

        int result = 0;
        for(int r = 0; r < len; r++) {
            counter[s[r] - 'a']++;

            while((counter[0] * counter[1] * counter[2]) != 0) {
                counter[s[l] - 'a']--;
                l++;
            }
            result += l;
        }

        return result;
    }
};