class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currentState = -1;
        int latest1 = -1;
        for(int i = 0; i < 32; i++){
            int x = (n&1);
            if(currentState != x){
                currentState = x;
            }
            else return false;
            n >>= 1;
            if(n == 0) break;
        }
        return true;
    }
};