class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int len = s.length();
        vector<int> dp(len+2, 0);

        for(int i = 0; i < len; i++) {
            int curr = 0;
            dp[i+1] = dp[i];
            // cek untuk len k+1 (gaboleh -1 soalnya at least k)
            if(i >= k && isPalindrome(s, i-k, i)) {
                // cek kalau palindrome atau bukan
                dp[i+1] = max(dp[i+1], 1 + dp[i-k]);

            }
            // cek untuk len k
            if(i >= k-1 && isPalindrome(s, i-k+1, i)) {
                    // cek kalau palindrome atau bukan
                dp[i+1] = max(dp[i+1], 1 + dp[i-k+1]);
            }
        }
        return dp[len];
    }
};