class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        st1 = 3600 * int(endTime[0:2]) 
        st2 = 3600 * int(startTime[0:2])
        st1 += 60 * int(endTime[3:5]) 
        st2 += 60 * int(startTime[3:5])
        st1 += int(endTime[6:]) 
        st2 += int(startTime[6:])
        return st1 - st2
