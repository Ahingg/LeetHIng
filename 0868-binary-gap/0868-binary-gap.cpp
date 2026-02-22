class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        int currLen = -1;
        while(n) {
            if(currLen == -1) {
                if(n&1) currLen = 0; 
            }
            else {
                if(n&1) {
                    result = max(currLen+1, result);
                    currLen = 0;
                }
                else currLen++;
            }
            n >>= 1;
        }
        return result;
    }
};