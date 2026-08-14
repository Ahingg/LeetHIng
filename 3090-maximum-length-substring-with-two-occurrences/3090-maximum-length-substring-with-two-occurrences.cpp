class Solution {
public:
    int maximumLengthSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        vector<int> freq(26, 0);
        int i = 0;
        int maxLen = 0;
        for(int j = 0; j < s.length(); j++) {
            freq[s[j] - 'a']++;

            while(freq[s[j] - 'a'] > 2) {
                freq[s[i++] - 'a']--;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};