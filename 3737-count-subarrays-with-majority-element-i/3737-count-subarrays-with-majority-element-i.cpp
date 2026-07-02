class FenwickTree {
public:
    int size;
    vector<int> tree;

    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for(; idx <= size; idx += idx & -idx) tree[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for(; idx > 0; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }
};

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();

        FenwickTree b((2 * n) + 2);
        int offset = n + 1;

        long long total = 0;
        int currPref = 0;

        b.update(currPref + offset, 1);

        for(int x: nums) {
            if(x == target) currPref++;
            else currPref--;

            int valid = b.query(currPref + offset - 1);
            total += valid;

            b.update(currPref + offset, 1);
        }
        return total;
    }
};