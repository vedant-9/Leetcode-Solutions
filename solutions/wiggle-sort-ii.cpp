// https://leetcode.com/problems/wiggle-sort-ii

class Solution {
public:
    void wiggleSort(vector<int>& a) 
    {
        vector<int> b(a);
        sort(b.begin(), b.end());
        for (int i=a.size()-1, j=0, k=i/2+1; i>=0; i--)
            a[i] = b[i&1 ? k++ : j++];
    }
};