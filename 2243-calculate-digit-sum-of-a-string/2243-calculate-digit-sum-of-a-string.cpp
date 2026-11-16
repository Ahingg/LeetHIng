class Solution {
public:
    int K, len;
    string process(string s) {
        // cout <<"len: " << s.length() << endl;
        if(s.length() == 1) return s;
        int sum = 0;
        for(auto c: s) {
            if(c >= '0' && c <= '9') sum += (c - '0');            
        }
        return to_string(sum);
    }
    
    int getLen(string& s) {
        int cnt = 0;
        for(auto c: s) if(c >= '0' && c <= '9') cnt++;
        return cnt;
    }

    string cut(string s) {
        int i = 0, buff = 0;
        string res = "", s2 = "";
        while(buff < K && i < s.length()) {
            // cout << "i: " << i << " " << s[i] << " " << buff << endl;
            s2 += s[i];
            i++;
            buff++;
            
            if(buff >= K) {
                buff = 0;
                // cout << "string: " << s2 << endl;
                res += process(s2);
                // cout << "result: " << res << endl << endl; 
                s2 = "";
            }
        }
        if(!s2.empty()) res += process(s2);
        // cout << res << endl;
        return res;
    }
    string digitSum(string s, int k) {
        K = k; len = s.length();
        // pecah jadi beberapa, per isinya size k
        
        while(true) {
            if(s.length() <= k) return s;
            s = cut(s);
        }
        // if(res.length() <= k) return res;
        // return process(res);
        return s;
    }
};