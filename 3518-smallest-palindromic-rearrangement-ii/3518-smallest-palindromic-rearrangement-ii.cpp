class Solution {
public:
    typedef long long ll;
    const ll LIMIT = 1e6;
    ll nCr(int n, int r) {
        if(r < 0 || r > n) return 0;
        if(r == 0 || r == n) return 1;
        r = min(r, n-r);
        ll res = 1;
        for(int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res >= LIMIT) return LIMIT;
        }
        return res;
    }

    ll getWays(const vector<int>& freq, int total) {
        ll res = 1;
        int rem = total;
        for(int f: freq) {
            if(!f) continue;
            res *= nCr(rem, f);
            if(res >= LIMIT) return LIMIT;
            rem -= f;
        }
        return res;
    }


    string smallestPalindrome(string s, int k) {
        int len = s.length();
        int len2 = len / 2;
        vector<int> freq(26, 0);
        for(int i = 0; i < len/2; i++) freq[s[i]-'a']++;

        if(getWays(freq, len2) < k) return "";

        ll currK = k;
        for(int i = 0; i < len2; i++) {
            for(int j = 0; j < 26; j++) {
                if(!freq[j]) continue;
                freq[j]--;
                ll ways = getWays(freq, len2 - i - 1);
                if(ways >= currK) {
                    s[i] = 'a' + j;
                    break;
                } 
                currK -= ways;
                freq[j]++;
            }
        }

        for(int i = 0; i < len2; i++) {
            s[len-i-1] = s[i];
        }
        return s;
    }
};