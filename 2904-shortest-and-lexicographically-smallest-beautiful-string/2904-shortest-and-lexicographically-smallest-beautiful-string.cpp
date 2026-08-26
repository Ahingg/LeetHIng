class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        int len = s.length();
        vector<int> pref(len+1, 0);
        for(int i = 1; i <= len; i++) {
            pref[i] = pref[i-1] + s[i-1] - '0';
        }

        string temp = "";
        for(int l = k; l <= len; l++) {
            bool found = false;
            for(int i = 1; i + l - 1 <= len; i++) {
                int cnt = pref[i + l - 1] - pref[i-1];
                // cout << i << " " << i + l - 1 << ": " << cnt << endl;
                if(cnt != k) continue;
                found = true;
                string n = s.substr(i-1, l);
                if(temp.empty() || n < temp) temp = n; 
            }
            if(found) break;
        }

        return temp;
    }
};