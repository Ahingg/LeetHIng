class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int point = 0, extra = 0;
        for(auto& c: moves) {
            if(c == '_') extra++;
            else point += (c=='R') ? 1 : -1;
        }
        return abs(point) + extra;
    }
};