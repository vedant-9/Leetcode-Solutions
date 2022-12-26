// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences

class Solution:
    def mostWordsFound(self, a: List[str]) -> int:
        mx = 0
        for s in a:
            w = s.split()
            if(len(w)>mx):
                mx=len(w)
        return mx