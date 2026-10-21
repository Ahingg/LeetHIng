class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), x = n;
        int minIdx = 0, maxIdx = 0;
        int point = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] < s[minIdx]) minIdx = i;
            else if(s[i] >= s[maxIdx]) maxIdx = i;
            if(s[i] < s[i-1]) point--;
            else if(s[i] > s[i-1]) point++;
            else x--;
        }
        if(point == x-1) return 0;
        if(n == 2) return -1;
        if(minIdx == 0 || maxIdx == n-1) return 1;
        if(minIdx != n-1 || maxIdx != 0) return 2;
        return 3;
    }
};