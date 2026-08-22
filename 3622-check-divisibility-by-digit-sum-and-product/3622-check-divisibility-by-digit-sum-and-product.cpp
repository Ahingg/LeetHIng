class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 0, b = 1;
        int c = n;
        while(c) {
            int x = c % 10;
            a += x;
            b *= x;
            c /= 10;
        }
        return ((n % (a+b)) == 0);
    }
};