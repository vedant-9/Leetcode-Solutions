// https://leetcode.com/problems/previous-permutation-with-one-swap

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        // prev permutation 
        int n = a.size();
        
        // Stop at when a[i-1]>a[i]
        int i = n-2;
        while(i>=0 and a[i]<=a[i+1]) 
            i--;
        
        // already smallest perm
        if(i==-1)
            return a;
        
        // find just smaller element than a[i] and it should not have duplicate
        int j = n-1;
        while(j>i and (a[j]>=a[i] or a[j]==a[j-1])) 
            j--;
        
        // swap operation 
        swap(a[i],a[j]);
        
        return a;
    }
};