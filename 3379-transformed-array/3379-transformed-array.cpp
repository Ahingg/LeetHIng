class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int x = abs(nums[i])%n;
            result[i] = nums[((nums[i] < 0) ? n + i - x : i+x)%n];

            // if(x > 0) result.push_back(nums[(x+i)%n]);
            // else if(x < 0) {
            //     cout << n+(i+(x%n)) << " " << i+(x%n);
            //     result.push_back(nums[((abs(x) > i) ? (n+(i+(x%n)))%n : (i+(x%n)%n))]);
            // }
            // else result.push_back(0);

        }
        return result;
    }
};