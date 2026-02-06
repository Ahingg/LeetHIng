class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int N = nums.size();
        if(N == 1) return 0;
        int i = 0, wSize = 1;
        sort(nums.begin(), nums.end());
        while((i + wSize) <= N){
            int nj = nums[i+wSize-1], ni = nums[i];
            int res = ceil((float)nj / (float)ni);
            // cout << ceil((float)nj / (float)ni) << endl;
            if(res <= k) wSize++;
            else i++; 
        }
        return N - wSize + 1;

    }
};