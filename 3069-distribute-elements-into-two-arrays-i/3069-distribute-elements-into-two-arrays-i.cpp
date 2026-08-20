class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        int arr2 = 1;
        result.push_back(nums[0]);
        nums[0] = -1;
        int arr1 = 0;
        for(int i = 2; i < n; i++) {
            if(result[arr1] > nums[arr2]) {
                result.push_back(nums[i]);
                nums[i] = -1;
                arr1 = result.size() - 1;
            }
            else {
                arr2 = i;
            }
        }

        for(int i = 0; i < n; i++) 
        {
            // cout << nums[i] << endl;
            if(nums[i] != -1) result.push_back(nums[i]);
        }
        return result;
    }
};