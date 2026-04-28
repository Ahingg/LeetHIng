class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat;

        // odd - odd = even
        // even - even == even
        // even - odd or odd - even = odd
        bool oddExist = false, evenExist = false;
        for(auto& r: grid){
            for(int& v: r) {
                if(v & 1) oddExist = true;
                else evenExist = true;
                flat.push_back(v);
            }
        }

        sort(flat.begin(), flat.end());

        int mid = flat.size() / 2;

        // if x is even and there exists mix of odd and even in flat, then there won't be any solution as
        // the odd will always be odd and the even will be even
        if(!(x&1) && oddExist && evenExist) return -1;

        int result = 0;
        for(auto v: flat) {
            if(v == flat[mid]) continue;
            int ops = abs(flat[mid] - v);
            if((ops % x) != 0) return -1;
            result += (ops / x);
        }

        return result;

    }
};