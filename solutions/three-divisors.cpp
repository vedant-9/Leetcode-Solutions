// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) 
    {
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>3)
                break;
            if(n%i==0)
                cnt++;
        }
        return cnt==3;
    }
};