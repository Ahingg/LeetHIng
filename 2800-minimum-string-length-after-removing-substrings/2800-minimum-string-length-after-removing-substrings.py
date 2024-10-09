class Solution:
    def minLength(self, s: str) -> int:
        lenStr = len(s)
        lenTemp = -1
        while lenStr != lenTemp:
            lenTemp = lenStr
            a = s.split("AB")
            a = "".join(a)
            a = a.split("CD")
            a = "".join(a)
            s = a
            lenStr = len(a)
        
        return lenStr

        