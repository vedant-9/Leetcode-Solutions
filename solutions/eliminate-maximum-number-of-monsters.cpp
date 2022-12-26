// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& a, vector<int>& b) 
    {
        int n = a.size();
        vector<double> c(n);
        for(int i=0;i<n;i++)
        {
            c[i] = a[i]*1.0/b[i];
        }
        
        sort(c.begin(),c.end());
        
        int ans = 0;
        int i = 0;
        for(int t=0;i<n;t++,i++)
        {
            cout<<c[i]<<" ";
            if(t>=c[i])
                break;
            ans++;
        }
        return max(ans,1);
    }
};