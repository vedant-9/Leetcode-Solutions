// https://leetcode.com/problems/sum-of-number-and-its-reverse

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0; i<=num; i++) {
            int j = 0, t = i;
            while(t) {
                j = j*10+t%10;
                t /= 10;
            }
            if(i+j == num) return true;
        }
        return false;
    }
};