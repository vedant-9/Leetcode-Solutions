// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    int n;
    vector<int> A;
    long tar;
    bool rec(int idx, int a, int b, int c, int d)
    {
        if(a>tar || b>tar || c>tar || d>tar)
            return false;
        if(idx==n)
        {
            if(a==b && b==c && c==d)
                return true;
            return false;
        }
        bool ans = false;
        ans |= rec(idx+1,a+A[idx],b,c,d);
        if(ans)
            return ans;
        ans |= rec(idx+1,a,b+A[idx],c,d);
        if(ans)
            return ans;
        ans |= rec(idx+1,a,b,c+A[idx],d);
        if(ans)
            return ans;
        ans |= rec(idx+1,a,b,c,d+A[idx]);
        return ans;
    }
    
    bool makesquare(vector<int>& a) 
    {
        n = a.size();
        sort(a.rbegin(),a.rend());
        long sum = 0;
        for(auto x:a) sum += x;
        if(sum%4!=0)
            return 0;
        tar = sum/4;
        A = a;
        return rec(0,0,0,0,0);
    }
};