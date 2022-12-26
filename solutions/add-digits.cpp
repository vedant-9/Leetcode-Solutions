// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int n) 
    {
        int sum = 0;
        while(n)
        {
            sum += n%10;
            n /= 10;
        }
        
        while(sum>9)  
        {
            int s = sum;
            sum = 0;
            while(s)
            {
                sum += s%10;
                s /= 10;
            }
        }
        
        return sum;
    }
};