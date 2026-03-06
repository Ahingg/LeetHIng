class Solution {
public:
    bool checkOnesSegment(string s) {
        int open = -1;
        for(auto c: s){
            if(open == -1 && c == '1'){
                open = 1;
            }
            else if (open == 1 && c == '0'){
                open = 0;
            } 
            else if (open == 0 && c == '1'){
            return false;
            }
            
        }
        return true;
    }
};