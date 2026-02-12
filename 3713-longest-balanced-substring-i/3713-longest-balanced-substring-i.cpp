class Solution {
public:
    int longestBalanced(string s) {
        int len = s.length();
        int maxLen = 0;
        for(int i = 0; i < len; i++){
            int count[26];
            memset(count, 0, 26*sizeof(int));
            int mx = -1e9;
            int unique = 0;
            for(int j = i; j < len; j++){
                int curLen = j-i+1;
                // if(curLen < maxLen) continue;
                int idx = s[j]-'a';
                if(!count[idx]) unique++;
                count[idx]++;
                mx = max(count[idx], mx);
                // cout << idx << " " << unique << endl;
                if(unique*mx == curLen) {
                    maxLen = max(curLen, maxLen);
                }
            }
        }
        return maxLen;
    }
};