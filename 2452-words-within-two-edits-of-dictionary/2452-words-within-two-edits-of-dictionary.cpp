class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int dn = dictionary.size();

        vector<string> result;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < dn; j++) {
                int l = queries[i].length();
                if(l != dictionary[j].length()) continue;
                int miss = 0;
                for(int k = 0; k < l; k++){
                    if(queries[i][k] != dictionary[j][k]) miss++;
                    if(miss > 2) break;
                }
                if(miss <= 2) {
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        return result;
    }
};