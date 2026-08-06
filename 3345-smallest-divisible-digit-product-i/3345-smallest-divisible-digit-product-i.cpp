class Solution {
public:
    int getDigitProduct(int i) {
        int temp = 1;
        while(i) {
            temp *= (i%10);
            i /= 10;
        }
        return temp;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(i <= 100) {
            if(getDigitProduct(i) % t == 0) return i;
            i++;
        }
        return 0;
    }
};