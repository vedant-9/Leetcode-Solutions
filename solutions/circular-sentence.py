// https://leetcode.com/problems/circular-sentence

class Solution:
    def isCircularSentence(self, s: str) -> bool:
        l = s.split()
        for i in range(0,len(l)-1):
            if(l[i][-1] != l[i+1][0]):
                return False
        if(l[0][0] != l[len(l)-1][-1]):
            return False
        return True