class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        string bottom = to_string(low), top = to_string(high);
        string buffer = "123456789";
        int l = bottom.length(), r = top.length();
        vector<int> ans;
        for(int i = l; i <= r; i++){
            for(int j = 0; j <= 9 - i; j++) {
                string curr = buffer.substr(j, i);
                int currI = stoi(curr);
                if(currI >= low && currI <= high) ans.push_back(currI);
                else if(currI > high) break;
            }
        }    
        return ans;
    }
};