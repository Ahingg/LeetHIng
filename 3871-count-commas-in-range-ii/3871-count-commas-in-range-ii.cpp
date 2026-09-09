class Solution {
public:
    typedef long long ll;
    ll countCommas(long long n) {
        ll t = 1000;
        ll len = 4;
        if(n < t) return 0;
        ll total = 0;
        while(true) {
            ll next = t * 10;
            ll mul = (len - 1)/3;
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