class Solution {
public:
    int maxProduct(int n) {
        int a = -1;
        int b = -1;
        while(n) {
            int digit = n%10;
            if(digit > a) {
                b = a;
                a = digit;
            }
            else if(digit > b) {
                b = digit;
            }
            n /= 10;
        }
        return a * b;
    }
};