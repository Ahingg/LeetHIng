class Solution {
public:
    int getBitCount(int x){
        int count = 0;
        while(x) {
            if(x&1) count++;
            x >>= 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int len = arr.size();
        for(int i = 0; i < len-1; i++){
            for(int j = 0; j < len-i-1; j++){
                int bit1 = getBitCount(arr[j]), bit2 = getBitCount(arr[j+1]);
                if(bit1 > bit2 || (arr[j] >= arr[j+1] && bit1 == bit2)){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
    }
};