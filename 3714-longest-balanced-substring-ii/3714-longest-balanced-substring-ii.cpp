

class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2> &p) const {
            // Hash the individual elements
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Combine the hashes (using a common bit-shifting trick)
            // 0x9e3779b9 is a golden ratio constant to help avoid collisions
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
public:
    static const int MAXN = 1e5;
    int count[3][MAXN];

    int getLengthForSpecific(string& s, vector<int> alphabet, const int len){
        int printOk = alphabet.size() == 2 && alphabet[0] == 0 && alphabet[1] == 1;
        if(alphabet.size() == 1) {
            int maxL = 0, i = 0;
            char target = 'a' + alphabet[0];
            for(char c: s){
                if(c == target) maxL = max(maxL, ++i);
                else i = 0;
            }
            return maxL;
        }

        unordered_map<pair<int, int>, int, pair_hash> diffLoc;
        diffLoc[{0,0}] = -2;
        int count[3] = {0,0,0};
        int maxLen = 0;
        for(int i = 0; i < len; i++){
            count[s[i]-'a']++;
            
            bool is_active = false;
            for(int a: alphabet) if(s[i]-'a' == a) is_active = true;
            if(!is_active){
                diffLoc = {};
                count[0] = count[1] = count[2] = 0;
                diffLoc[{0,0}] = i+1;
                continue;
            }

            int dif1 = count[alphabet[1]] - count[alphabet[0]];
            int dif2 = (alphabet.size() == 3) ? count[alphabet[1]] - count[alphabet[2]] : 0;
            
            if(diffLoc[{dif1, dif2}]){
                if(diffLoc[{dif1, dif2}] == -2) maxLen = max(maxLen, i+1);
                else maxLen = max(maxLen, i-diffLoc[{dif1, dif2}]+1);
            }
            else diffLoc[{dif1, dif2}] = i+1;
            // if(printOk) {
            //     printf("%d: %d %d\n", i, dif1, dif2);
            //     printf("%d\n", diffLoc[{dif1, dif2}]);
            // }
        }
        return maxLen;
    }
    
    int longestBalanced(string s) {
        const int len = s.length();
        int maxResult = 0;
        maxResult = max(maxResult, getLengthForSpecific(s, {0}, len));
        maxResult = max(maxResult, getLengthForSpecific(s, {1}, len));
        maxResult = max(maxResult, getLengthForSpecific(s, {2}, len));
        maxResult = max(maxResult, getLengthForSpecific(s, {0,1}, len));
        maxResult = max(maxResult, getLengthForSpecific(s, {1,2}, len));
        maxResult = max(maxResult, getLengthForSpecific(s, {0,2}, len));
        maxResult = max(maxResult, getLengthForSpecific(s, {0,1,2}, len));
        return maxResult;
    }
};