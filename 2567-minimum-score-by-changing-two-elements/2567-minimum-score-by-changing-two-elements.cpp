class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // tinggal cek mana yang diffnya lebih kecil
        int n = nums.size();
        if(n == 3) return 0;
        sort(nums.begin(), nums.end());
        // kalau ada 4, tinggal ilangin 01 atau ga 23
        // cek mana yang worth untuk di ubah, 2 awal atau 2 akhir
        // ketika diuubah pasti jadi 2 angka sama karena kita mau jadiin 0 sebagai diff minimalnya.
        // kalau yang di 0 in adalah 2 pertama, maka target next nya adalah nums[n-1] - nums[2] 
        // kalau yang di 0 in adalah 2 terakhir, target nextnya adalah nums[n-1] - n[0]
        return min({nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1]});
    }
};
// 8 28 42 58 75
// kalau 8 sama 75 dijadiin angka yang sama, jadinya
        // int min1 = 1e9+7, min2 = 1e9+7;
        // int max1 = -1, max2 = -1;
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] > max1) {
        //         max2 = max1;
        //         max1 = nums[i];
        //     }
        //     else if(nums[i] <= max1 && nums[i] >= max2) {
        //         max2 = nums[i];
        //     }

        //     if(nums[i] < min1) {
        //         min2 = min1;
        //         min1 = nums[i];
        //     }
        //     else if(nums[i] >= min1 && nums[i] <= min2) {
        //         min2 = nums[i];
        //     }
        // }