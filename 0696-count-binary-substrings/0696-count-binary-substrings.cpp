class Solution {
public:
    int countBinarySubstrings(string s) {
        int count[2] = {0,1};
        int total = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) count[1]++;
            else{
                total += min(count[0], count[1]);
                count[0] = count[1];
                count[1] = 1;
            } 
        }
        return total + min(count[0], count[1]);
    }
};