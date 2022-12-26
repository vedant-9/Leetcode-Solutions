// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& a) 
    {
        int n = a.size();
        
        int i,j;
        for(i=n-2;i>=0 && a[i]>=a[i+1];i--);
    
        if(i>=0)
        {  
            for(j=n-1;j>i && a[j]<=a[i];j--);

            swap(a[i],a[j]);
        }

        reverse(a.begin()+i+1,a.end());
    }
};