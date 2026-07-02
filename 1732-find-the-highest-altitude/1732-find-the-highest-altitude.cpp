class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int curr = 0;
        for(auto x: gain) {
            curr += x;
            result = max(curr, result);
        }

        return result;
    }
};