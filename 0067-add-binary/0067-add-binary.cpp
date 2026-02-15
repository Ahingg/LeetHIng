class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int i = 0;
        string result = "";
        int excess = 0;
        int maxLen = max(len1, len2);
        while(i < maxLen){
            int digit1 = len1 - i - 1 >= 0 ? a[len1-i-1] - '0' : 0;
            int digit2 = len2 - i - 1 >= 0 ? b[len2-i-1] - '0' : 0;
            cout << i << ": "<< digit1 << " " << digit2 << endl;
            if(digit1 == digit2) {
                result.insert(0, 1, excess ? '1' : '0');
                if(!digit1 && excess) excess--;
                if(digit1 && !excess) excess++;
            }
            else{
                result.insert(0, 1, excess ? '0' : '1');
            }
            i++;
        }
        if(excess) result.insert(0, 1, '1');
        return result;
    }
};