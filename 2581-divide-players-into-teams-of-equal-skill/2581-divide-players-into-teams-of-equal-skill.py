class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        sort = sorted(skill)
        sum = 0
        lastIndex = len(sort)-1
        v = sort[0] + sort[lastIndex]
        for i in range(int(len(skill)/2)):
            print(sort[0], sort[lastIndex])
            if not(sort[0] + sort[lastIndex] == v):
                return -1
            sum += sort[0] * sort[lastIndex]
            sort.pop(lastIndex)
            sort.pop(0)
            lastIndex -= 2
            

        return sum
        