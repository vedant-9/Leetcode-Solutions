// https://leetcode.com/problems/maximum-number-of-balls-in-a-box

class Solution {
public:
    int countBalls(int l, int h) 
    {
        int A[100] = {0};
        for(int i=l;i<=h;i++)
        {
            int t =i,s=0;
            while(t)
            {
                s += t%10;
                t /= 10;
            }
            A[s]++;
        }
        return *max_element(A,A+100);
    }
};