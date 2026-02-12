class Solution {
public:
    int longestBalanced(string s) {
        map<int, int> count;
        int len = s.length();
        int maxLen = 1;
        for(int i = 0; i < len; i++){
            count.clear();
            vector<int> arr;
            cout << i << endl;
            for(int j = i; j < len; j++){
                int idx = s[j]-'a';
                if(!count[idx]) arr.push_back(idx);
                count[idx]++;

                int l = count[arr[0]];
                for(auto idx: arr){
                    if(count[idx] != l) {
                        l = -1;
                        break;
                    }
                }
                if(l != -1) maxLen = max(maxLen, j-i+1);
            }
            
        }
        return maxLen;
    }
};