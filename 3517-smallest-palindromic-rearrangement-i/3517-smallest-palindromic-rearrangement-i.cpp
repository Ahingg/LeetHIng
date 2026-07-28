class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();

        vector<int> cnt(26, 0);
        for(const char c: s) cnt[c - 'a']++;
        string result = "";
        string result2 = "";
        int oddIdx = -1;
        for(int i = 0; i < 26; i++) {
            if(!cnt[i]) continue;
            if(cnt[i] & 1) oddIdx = i;
            for(int j = 0; j < (cnt[i]/2); j++) {
                result += ('a' + i);
                result2 += ('a' + i);
            }
        }
        reverse(result2.begin(), result2.end());
        if(oddIdx != -1) result += ('a' + oddIdx);
        result += result2;
        return result;
    }
};