// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) 
    {
        int n = a.size();
        vector<int> ans;
        
        int i = 0, j = n-1;
        while(i<=j)
        {
            if(a[i]*a[i]>a[j]*a[j])
                ans.push_back(a[i]*a[i]),i++;
            else
                ans.push_back(a[j]*a[j]),j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};