class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for(auto& x: words){
            int total = 0;
            for(auto c: x) {
                total += weights[c - 'a'];
            }
            result.push_back('a' + 26 - 1 - (total%26));
        }
        return result;
    }
};