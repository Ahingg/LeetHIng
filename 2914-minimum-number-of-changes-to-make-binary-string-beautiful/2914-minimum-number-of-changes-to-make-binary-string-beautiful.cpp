class Solution {
public:
    int minChanges(string s) {
        // untuk mencari yang paling optimal, tinggal cari perpotongan yang paling minimal perubahannya, dengan cara cek so far ada berapa 0 dan 1 di potongan kiri dan kanan, 
        int n = s.length();
        int ans = 0;
        for(int i = 1; i < n; i+=2) {
            if(s[i] != s[i-1]) ans++;
        }
        return ans;
    }
};