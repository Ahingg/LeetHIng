class Solution {
public:
    vector<int> generateLPS(string& pattern) {
        int m = pattern.length();
        int len = 0;
        vector<int> lps(m, 0);
        int i = 1;
        while(i < m) {
            if(pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else { 
                if(len != 0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    string generateString(string str1, string str2) {
        int n = str1.length(), m = str2.length();

        string ans(n + m - 1, '?');
        vector<bool> isFixed(n+m-1, false);
        
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++){
                    if(ans[i+j] != '?' && ans[i+j] != str2[j]) {
                        return "";
                    }
                    ans[i+j] = str2[j];
                    isFixed[i+j] = true;
                }
            }
        }
        for(auto& c: ans) {
            if(c == '?') c = 'a'; 
        }

        vector<int> lps = generateLPS(str2);

        int i = 0, j = 0;
        while(i < n + m - 1) {
            if(ans[i] == str2[j]) {
                i++;
                j++;
            }

            if(j == m) {
                int start = i - m;
                if(start < n && str1[start] == 'F') {
                    int idx = -1;
                    for(int k = i - 1; k >= start; k--){
                        if(!isFixed[k]){
                            idx = k;
                            break;
                        }
                    }

                    if(idx == -1) return "";

                    ans[idx] = 'b';
                    isFixed[idx] = true;

                    i = idx;
                    j = 0;
                }
                else {
                    j = lps[j-1];
                }
            }
            else if(i < n + m - 1 && ans[i] != str2[j]) {
                if(j != 0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        return ans;
    }
};