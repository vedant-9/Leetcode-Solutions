// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) 
    {
//         5! = 5 x 4 x 3 x 2 x 1
//         5/2 = 2
//         5/2^2 = 1
//         2 -> 3
            
//         5/5  =1
            
//         8! = 
//         8/2 = 4
//         8/2^2 = 2
//         8/2^3 = 1
//         2 -> 7
            
        int c2 = 0,i=1;
        while(1)
        {
            int t = n/(pow(2,i));
            if(t==0)
                break;
            c2 += t;
            i++;
        }
        
        int c5 = 0;
        i =1;
        while(1)
        {
            int t = n/(pow(5,i));
            if(t==0)
                break;
            c5 += t;
            i++;
        }
        
        return min(c2,c5);
        
    }
};