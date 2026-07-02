class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int len = text.length();
        vector<int> list(26, 0);
        for(auto c: text) list[c - 'a']++;
        int counter = 0;

        int b = list['b'-'a'],a = list[0],l = list['l' - 'a'] / 2;
        int o = list['o'-'a'] /  2,n = list['n' - 'a'];
        // printf("%d %d %d %d %d\n", b,a,l,o,n);
        int minAmt = min(b, min(a, min(l, min(o, n))));
        return minAmt;
    } 
};