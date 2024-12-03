class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        if arr.count(0) > 1:
            return True
        for x in arr:
            
            if x*2 in arr and x != 0:
                return True
        return False        


        