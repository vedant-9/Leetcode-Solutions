// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& D) 
    {
        int c = 0;
        int n = D.size();
        D[n-1]++;
        if(D[n-1]>=10)
            c = D[n-1]/10,D[n-1] = D[n-1]%10;
        else
            return D;
        for(int i=n-2;i>=0;i--)
        {
            D[i] += c;
            c = D[i]/10;
            D[i] = D[i]%10;
        }
        while(c)
        {
            D.insert(D.begin(),c%10);
            c /= 10;
        }
        return D;
    }
};