class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int k = 0;
        int even = 0;
        vector<int> freq(11, 0);
        for(int i = 0; i < digits.size(); i++) {
            if(freq[digits[i]] == 0) k++;
            if(freq[digits[i]] == 0 && digits[i] % 2 == 0) even++;
            freq[digits[i]]++;
        }

        // where every digit is different: 
        // pick one numbr, then the next number has one less choice
        // even * (k-1) * (k-2)
        int first = (even) * (k-1)*(k-2);
        // 2 same digit
        // check for every possibility
        // last must be an even number
        // xxy, xyx. yxx
        // each number will take charge for xyx and yxx
        // for xxy, then we need to check for 2 case
        // if x is even then y must be even-1
        // if x is odd then y must be even
        int second = 0;
        int third = 0;
        for(int i = 0; i < 10; i++) {
            if(freq[i] >= 2) {
                if(i % 2 == 0) second += (2*(k-1))+ (even-1);
                else second += even; // cast xxy if x odd
            }
            if(freq[i] >= 3 && (i % 2 == 0)) third++;
        }
        int total = first + second + third;
        // cout << first << " " << second << " " << third << endl;
        // subtract with the beginning of 0
        // case: 0xy, 0xx, 0x0, 000 dan 00x
        // for case 000, 0x0
        if(freq[0] >= 3) total--; // 000
        if(freq[0] >= 2) {
            total -= (even-1); // 00x can only be even case
            total -= (k-1); // 0x0
            // 0xx
            // for every even x
        }
        // 0xy
        // cout << total << endl;
        if(freq[0] >= 1) {
            for(int i = 0; i < 10; i++) {
                if(freq[i] == 0 || i == 0) continue;
                if(freq[i] >= 2 && (i % 2 == 0)) total--;
            }
            total -= (even-1) * (k-2);
        }
        return total;
    


    }
};