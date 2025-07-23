class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        leftIndex = 0
        rightIndex = len(nums) - 1

        my_map = {}

        for i, x in enumerate(nums):
            my_map[i] = x
        msorted_by_value = sorted(my_map.items(), key=lambda item: item[1])
        # print(msorted_by_value)
        # print(msorted_by_value[0][0]) keys

        while(rightIndex > leftIndex):
            sumResult = msorted_by_value[leftIndex][1] + msorted_by_value[rightIndex][1]
            if sumResult == target:
                return [msorted_by_value[leftIndex][0], msorted_by_value[rightIndex][0]]
            
            if sumResult < target:
                leftIndex += 1
                continue
            
            if sumResult > target:
                rightIndex -= 1
                continue
        return [0,0]