class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int len = s.length();

        vector<int> list;
        int currNum = 1;
        int buffer = 1;
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == '1') cnt++;
            if((s[i]-'0') == currNum) buffer++;
            else {
                list.push_back(buffer);
                buffer = 1;
                currNum = (currNum) ? 0 : 1;
            }
        }   
        if(currNum == 1) list.push_back(buffer+1);
        else {
            // cout << "Asas" << endl;
            list.push_back(buffer);
            list.push_back(1);
        }
        int n = list.size();
        if(n == 1) return cnt;
        // for(auto x: list) cout << x << " ";
        int ans = cnt;
        for(int i = 2; i < n-1; i+=2) {
            ans = max(ans, list[i-1] + cnt + list[i+1]);
        }
        return ans;
    }
};