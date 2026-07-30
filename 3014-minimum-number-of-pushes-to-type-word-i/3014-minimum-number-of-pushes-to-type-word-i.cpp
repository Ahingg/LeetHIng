class Solution {
public:
    int minimumPushes(string word) {
        int len = word.length();
        int layer = len / 8;
        int remain = len % 8;
        // (1 * i) + (2*i) ... = (1+2+3...) * layer
        return (((layer * (layer+1)) / 2) * 8) + (remain * (layer + 1)) ;
    }
};