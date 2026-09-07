class Solution {
public:
    long long MOD = 1e9+7;
    int distinctSubseqII(string s) {
        // untuk setiap len dari 1 sampai n
        // hitung kombinasi per huruf
        // dp[i][j] 
        // menandakan sebuah state untuk 
        int total = 0;
        vector<long long> last(26, 0);
        for(const char& c: s) {
            int new_count = (total + 1) - last[c - 'a'];
            // cout << new_count << " " << total << endl;
            total = ((total % MOD)+ (new_count%MOD) + MOD) % MOD;
            last[c - 'a'] = ((last[c-'a'] % MOD) + (new_count%MOD)) % MOD;
        }
        
        return total;
    }
};