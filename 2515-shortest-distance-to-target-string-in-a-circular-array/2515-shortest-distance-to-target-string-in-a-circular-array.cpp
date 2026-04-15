class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex] == target) return 0;
        int n = words.size();
        int result = 1e9;
        for(int i = startIndex; i < n + startIndex; i++) {
            int x = i % n;
            int temp = 1e9;
            if(words[x] == target) {
                if(x > startIndex) {
                    temp = min(temp, min(x - startIndex, startIndex + n - x));
                }
                else {
                    temp = min(temp, min(startIndex - x, i - startIndex));
                }
                result = min(temp, result);
            }
        }

        return result == 1e9 ? -1 : result;
    }
};