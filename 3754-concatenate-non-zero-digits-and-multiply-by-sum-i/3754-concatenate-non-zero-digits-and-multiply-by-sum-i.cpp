class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 1;
        long long nnum = 0;
        while(n) {
            sum += (n%10);
            nnum += (n%10) * x;
            x *= (n%10) ?  10 : 1;
            n /= 10;
        }
        return nnum*sum;
    }
};