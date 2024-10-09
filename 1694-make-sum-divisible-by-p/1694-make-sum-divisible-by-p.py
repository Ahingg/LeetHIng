class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)

        totalSum = 0

        for num in nums:
            totalSum = (totalSum + num) % p
        
        target = totalSum % p

        if target == 0:
            return target
        
        m = {0 : -1}
        currSum = 0
        lenMin = n

        for i in range(n):
            currSum = (currSum + nums[i]) % p

            need = (currSum - target + p)%p

            if need in m:
                lenMin = min(lenMin, i - m[need])
            
            m[currSum] = i

        return -1 if lenMin == n else lenMin
        