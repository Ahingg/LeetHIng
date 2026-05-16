class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        if(n == 3) return min(nums[0], min(nums[1], nums[2]));

        if(nums[0] < nums[1] && nums[0] < nums[n-1]) return nums[0];

        int l = 0;
        int r = n-1;
        int mid = -1;
        while(l <= r) {
            while(l < r && nums[l] == nums[l+1]) l++;
            while(r > l && nums[r] == nums[r-1]) r--;
            mid =(l+r)/2;
            while(mid < r && nums[mid] == nums[mid+1]) mid++;
            // cout << l << " " << mid << " " << r << endl; 
            int normLeft = (mid - 1 + n) % n;
            int normRight = (mid + 1) % n;
            if(nums[mid] > nums[normRight] || nums[normLeft] > nums[normRight]) return min(nums[normRight], nums[mid]);
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid - 1;
        } 
        return nums[mid];
    }
};