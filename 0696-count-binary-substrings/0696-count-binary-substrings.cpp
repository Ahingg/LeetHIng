class Solution {
public:
    int countBinarySubstrings(string s) {
        int count1 = 0, count0 = 0;
        if(s[0] - '0') count1++;
        else count0++;
        int total = 0;
        for(int i = 1; i < s.length(); i++) {
            int x = s[i] - '0';
            int y = (s[i-1] - '0');
            if(x){
                if(x == y) count1++;
                else count1 = 1; 
                if(count0 >= count1) {
                    total++;
                    cout << i << ": hit on " << count0 << " " << count1 <<  endl;
                }
            }
            else {
                if(x == y){
                    count0++;
                }
                else {
                    count0 = 1;
                }
                if(count0 <= count1) {
                    total++;
                    cout << i << ": hit on " << count0 << " " << count1 <<  endl;
                }
            }
        }
        return total;
    }
};