class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true; 
        bool res = false;
        for(int i = 0; i < 2;i++) {
            if((s1[i] == s2[i+2] && s2[i] == s1[i+2]) ||
            (s1[i] == s2[i] && s1[i+2] == s2[i+2])) res = true;
            else return false;
        } 
        return res;
    }
};