// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) 
    {
        int n = a.size();
        int i = 0, j = n-1;
        while(i<n && j>=0)
        {
            if(i%2==0 || a[i]%2!=0) i++;
            else if(j%2==1 || a[j]%2==0) j--;
            else swap(a[i++],a[j--]);
        }
        return a;
    }
};