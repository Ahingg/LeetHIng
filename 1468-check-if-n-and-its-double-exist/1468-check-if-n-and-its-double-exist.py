class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        w = {}

        for x in arr:
            if x / 2 not in w and x*2 not in w:
                w[x] = x*2
            else:
                return True
        return False        


        