class Solution {
public:

    // int count = 0;
    // string bloom(int n, int k, char curr){
    //     if(n == 1) {
    //         count++;
    //         string x = "";
    //         if(count == k) return x + curr;
    //         return "";            
    //     }
    //     char first, second;
    //     switch(curr) {
    //         case 'a':
    //             first = 'b';
    //             second = 'c';
    //             break;
    //         case 'b':
    //             first = 'a';
    //             second = 'c';
    //             break;
    //         case 'c':
    //             first = 'a';
    //             second = 'b';
    //             break;
    //     }
    //     string left = bloom(n-1, k, first);
    //     if(left != "") return curr + left; 
    //     string right = bloom(n-1, k, second);
    //     if(right != "") return curr + right;

    //     return "";
    // }
    string getHappyString(int n, int k) {
        int possible = (1 << (n-1));
        if(k > 3*possible) return "";
        string result = "";

        k--;
        int idx = k / possible;
        char startPoint = (char)('a' + idx);
        k %= possible;
        result += startPoint;

        for(int i = 1; i < n; i++){
            possible >>= 1;

            idx = k/possible;
            char back = result.back();
            char first = (back == 'a') ? 'b' : 'a';
            char second = (back == 'c') ? 'b' : 'c';

            if(idx == 0) result += first;
            else result += second;

            k %= possible;
        }

        return result;
    }
};