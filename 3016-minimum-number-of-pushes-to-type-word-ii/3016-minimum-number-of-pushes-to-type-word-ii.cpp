class Solution {
public:
    int minimumPushes(string word) {
        int len = word.length();
        vector<int> freq(26, 0);
        for(const char& c: word) freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());

        int sum = 0;
        for(int i = 0 ; i < 26; i++) {
            int layer = (i/8) + 1;
            sum += (freq[i] * layer);
        }
        return sum;
    }
};