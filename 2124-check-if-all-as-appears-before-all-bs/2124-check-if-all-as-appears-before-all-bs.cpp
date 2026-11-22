class Solution {
public:
    bool checkString(string s) {
        int a = -1, b = -1;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(b == -1 && s[i] == 'b') b = i;
            if(a == -1 && s[len-i-1] == 'a') a = len - i - 1;
        }
        // cout << a << " " << b << endl;
        return (a < b) || (a == -1) || (b == -1);
    }
};