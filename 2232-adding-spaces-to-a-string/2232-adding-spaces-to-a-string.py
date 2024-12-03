class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        index = 0
        last_index = len(spaces)
        string = ''
        for i,c in enumerate(s):
            if(index < last_index and i == spaces[index]):
                string += ' '
                index+=1
            string += c
        
        return string