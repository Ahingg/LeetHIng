class Solution {
public:
    typedef tuple<int, int, int> t3i;
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<t3i> s;

        for(int i = 0; i < n; i++) {
            int currLeft = i;
            int currMax = nums[i];

            while(!s.empty()){
                auto [val, left, right] = s.back();
                if(val <= nums[i]) break;

                currMax = max(val, currMax);
                currLeft = left;
                s.pop_back();
            }

            s.push_back({currMax, currLeft, i});
        }
        
        vector<int> result(n, -1);
        for(const auto& x: s){
            auto [val, left, right] = x;
            for(int i = left; i <= right; i++){
                result[i] = val;
            }
        }

        return result;
    }
};