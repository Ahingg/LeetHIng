class Solution {
public:
    typedef long long ll;
    char processStr(string s, long long k) {
        ll m = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z') m++;
            else if(s[i] == '*') m = max(0LL, m-1);
            else if(s[i] == '#') m <<= 1;
        }

        if(k >= m) return '.';

        for(int i = n-1; i >= 0; i--) {
            char c = s[i];

            if(c == '#') {
                m /= 2;
                if(k >= m) k -= m;
            }
            else if(c == '*') {
                m ++;
            }
            else if(c == '%') {
                k = m - 1 - k;
            }
            else {
                m--;
                if(k == m) return c;
            }
        }
        return '.';
    }
};