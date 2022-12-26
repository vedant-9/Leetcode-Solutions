// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& a) 
    {
        int n = a.size();
        
        int c = 0, mc = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                c++;
            else
            {
                mc = max(mc,c);
                c=0;
            }
        }
        int l = 0;
        for(;l<n && a[l]==0;l++);
        int ans = max({(mc+1)/2,c,l});
        return ans;
    }
};