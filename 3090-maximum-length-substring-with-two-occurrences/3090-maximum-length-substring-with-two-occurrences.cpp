class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n =  s.length();

        unordered_map<int, int> freq;
        int i = 0;
        int maxLen = 0;
        for(int j = 0; j < n; j++) {
            int idx = s[j] - 'a';
            freq[idx]++;

            while(freq[idx] > 2) {
                freq[s[i++] - 'a']--;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};