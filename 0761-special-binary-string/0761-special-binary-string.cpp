class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int count = 0, start = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') count++;
            else count--;

            if(count == 0){
                string sub = s.substr(start+1, i-start-1);
                res.push_back('1' + makeLargestSpecial(sub) + '0');
                start = i+1;
            }
        }
        sort(res.rbegin(), res.rend());

        string ans = "";
        for(auto s: res) ans += s;
        return ans;
    }
};