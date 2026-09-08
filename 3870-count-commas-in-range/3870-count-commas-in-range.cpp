class Solution {
public:
    int countCommas(int n) {
        // string s = to_string(n);
        // 1000 - 9999
        // 10.000 - 99.999
        int t = 1000;
        int len = 4;
        if(n < t) return 0;
        int total = 0;
        while(true) {
            int next = t * 10;
            int mul = (len - 1)/3;
            // kalau n > next, maka pakai next - t
            if(n >= next) total += ((next - 1) - t + 1) * mul;
            else {
                // cout << n - t + 1 << endl;
                total += (n - t + 1) * mul;
                break;
            }
            t = next;
            len++;
        }
        return total;
    }
};