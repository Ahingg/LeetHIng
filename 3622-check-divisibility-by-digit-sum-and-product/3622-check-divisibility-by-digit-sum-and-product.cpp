class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 0, b = 1;
        string x = to_string(n);
        for(const char& c: x) {
            a += c - '0';
            b *= c - '0';
        }
        return ((n % (a+b)) == 0);
    }
};