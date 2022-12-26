// https://leetcode.com/problems/water-bottles

class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        return (numBottles*numExchange-1)//(numExchange-1)