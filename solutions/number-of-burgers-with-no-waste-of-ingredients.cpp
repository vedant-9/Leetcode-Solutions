// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients

class Solution {
public:
    vector<int> numOfBurgers(int a, int b) 
    {
        if(a>4*b || a<2*b || a&1)
            return {};
        int x = a/2-b;
        if(x<0)
            return {};
        return {x,b-x};
    }
};