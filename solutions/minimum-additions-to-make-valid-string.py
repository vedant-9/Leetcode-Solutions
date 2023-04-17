class Solution:
    def addMinimum(self, word: str) -> int:
        w = word.replace("abc", "*")
        c1 = w.count("ab")
        w2 = w.replace("ab", "*")
        c2 = w2.count("bc")
        w4 = w2.replace("bc", "*")
        c6 = w4.count("ac")
        w3 = w4.replace("ac", "*")
        c3, c4, c5 = w3.count("a"), w3.count("b"), w3.count("c")
        return c1 + c2+ c6 + 2*(c3+c4+c5)
        
