class Solution {
public:
    int getBitCount(int x){
        int count = 0;
        while(x){
            count += (x & 1);
            x >>= 1;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        bool primeList[33] = {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true, false}; 
        int result = 0;
        for(int i = left; i <= right; i++){
            int count = getBitCount(i);
            if(primeList[count]) result++;
        }
        return result;
    }
};