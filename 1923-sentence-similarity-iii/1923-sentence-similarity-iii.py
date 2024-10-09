class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        a = sentence1.split()
        b = sentence2.split()
        if a == b:
            return True
        while a[0] == b[0]:
            print("test")
            a.pop(0)
            b.pop(0)
            if not(a and b):
                return not(a and b)
        while a[-1:] == b[-1:]:
            a.pop(len(a)-1)
            b.pop(len(b)-1)
            if not(a and b):
                return not(a and b)
        return not(a and b)



        