class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1, aSt;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st1.push(i);
            else if(s[i] == '*') aSt.push(i);
            else {
                if(!st1.empty()) st1.pop();
                else if(!aSt.empty()) aSt.pop();
                else return false;
            }
        }

        while(!st1.empty() && !aSt.empty()) {
            if(st1.top() < aSt.top()) {
                st1.pop();
                aSt.pop();
            }
            else return false;
        }

        return st1.empty();
    }
};