class Solution {
public:
    int minFlips(string s) {
        int len = s.length();
        int curr = 0, minVal = 1e9;
        char last = (len%2) + '0';
        for(int i = 0; i < len; i++){
            if(s[i] != ((i % 2) + '0')) curr++;
        }
        minVal = min(curr, len-curr);

        for(int i = 0; i < len-1; i++){
            // all s[i] will be left shifted once,
            // interchange curr (010101..) with change(101010110)
            if(s[i] == '1') curr--;
            curr = len-curr-1;
            if(s[i] != (((len-1)%2) + '0')) curr++;
            minVal = min(minVal, min(curr, len-curr));
        }
        return minVal;
    }
};