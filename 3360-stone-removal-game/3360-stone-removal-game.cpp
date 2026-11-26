class Solution {
public:
    bool canAliceWin(int n) {
        // 10 9 8 7 6 5 4 3 2 1
        // 10 19 27 34 40 45 49 52 54 55
        vector<int> ch = {10, 19, 27, 34, 40, 45, 49, 52, 54, 55};
        for(int i = 0; i < 10; i++) {
            if(n < ch[i] && i % 2 == 0) return false;
            if(n < ch[i] && i % 2 == 1) return true;
        }
        return true;
    }
};