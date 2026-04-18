class Solution {
public:
    int mirrorDistance(int n) {
        int num = n, result = 0;
        while(num) {
            result = (result * 10) + (num%10);
            num /= 10;
        } 
        return abs(result - n);
    }
};