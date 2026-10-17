class Solution {
public:
    typedef pair<int, int> pii;
    int acc(int n) {
        int total = 0;
        while(n) {
            total += n % 10;
             n /= 10;
        }

        return total;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pii> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back({acc(nums[i]), i});
        }
        sort(temp.begin(), temp.end(), [&nums](const pii a, const pii b){
            if(a.first == b.first) {
                return nums[a.second] < nums[b.second];
            }

            return a.first < b.first;
        });
        int ans = 0;

        // 18, 43, 34, 16
        // 16, 34, 43, 18
        // 3   2   1   0
        vector<bool> visited(n, false);
        for(int i = n-1; i >= 0; i--) {
            while(temp[i].second != i) {
                swap(temp[i], temp[temp[i].second]);
                ans++;
            }
        }
        return ans; 
    }
};