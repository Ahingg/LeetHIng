class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0;
        int sum = 0;

        for(auto n: nums){
            sum += n;
        }
        int currentSum = 0;
        for(auto n: nums){
            currentSum += n;
            if(currentSum == sum) break;
            if((currentSum - (sum - currentSum)) % 2 == 0) count++;
        }
    
        return count;
    }
};