class Solution {
public:
    typedef pair<int, int> pii;
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 	return pos_a.x < pos_b.x + size_b.w \
		// and pos_b.x < pos_a.x + size_a.w \
		// and pos_a.y < pos_b.y + size_b.h \
		// and pos_b.y < pos_a.y + size_a.h
        // x, y
        pii pos_a = {rec1[0], rec1[3]};
        pii pos_b = {rec2[0], rec2[3]};
        pii size_a = {rec1[2] - rec1[0], rec1[3] - rec1[1]};
        pii size_b = {rec2[2] - rec2[0], rec2[3] - rec2[1]};

        // -6, 2 | 15, 12
        // 0, 8  | 4, 3
        // -6 < 4
        return rec1[0] < rec2[2] &&  rec1[1] < rec2[3] && rec2[0] < rec1[2] &&  rec2[1] < rec1[3];
    }
};