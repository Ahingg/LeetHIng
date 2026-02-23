class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length();
        if(s.length() <= k) return false;
        
        unordered_set<string> list;
        for(int i = 0; i + k <= len; i++){
            list.insert(s.substr(i, k));
        }
        return list.size() == (1 << k);

    }
};