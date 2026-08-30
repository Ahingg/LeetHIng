class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        // cek all the way to right
        // cek all the way ke left
        // cek 2 way
        // cari aja indexnya bru dipikirin

        int minIdx = 0, maxIdx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[maxIdx]) maxIdx = i;
            if(nums[i] < nums[minIdx]) minIdx = i;
        }

        // cout << nums[minIdx] << " " << nums[maxIdx] << endl; 

        // tinggal cari aja kalo minIdx - maxIdx < 0, maka min ada di kanan max
        // begitu juga sebaliknya
        /// case 1, cek satu runtutuan dari kiri
        int ans = -1;
        if(maxIdx > minIdx) {
            ans = min(min(maxIdx + 1, minIdx + 1 + n - maxIdx), n - minIdx);
        }
        else {
            ans = min(min(minIdx + 1, maxIdx + 1 + n - minIdx), n - maxIdx);
        }

        return ans; 
    }
};