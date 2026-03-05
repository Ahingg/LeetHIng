class Solution {
public:
    int minOperations(string s) {
        int len = s.length();
        int change1 = 0;
        for(int i = 0; i < len; i++){
            if(s[i] != ((i % 2) + '0')) change1++;
        }
        // cout << change1 << " " << len - change1;
        return min(change1, len-change1);
    }
};