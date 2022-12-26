// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& A, int val) 
    {
        int j = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=val)
                A[j++]=A[i];
        }
        return j;
    }
};