// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) 
    {
        int n = a.size();
        sort(a.begin(),a.end());
        
        int i = 0, j = n-1;
        vector<int> b;
        for(int k=0;k<=n/2;k++)
        {
            b.push_back(a[i++]);
            if(i<j)
                b.push_back(a[j--]);
        }
        return b;
    }
};