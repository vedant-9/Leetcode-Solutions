// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> b(a); 
        sort(b.begin(),b.end());
        int n=a.size();
        int i=0; while(i<n and b[i]==a[i]) i++;
        int j=n-1; while(j>=0 and b[j]==a[j]) j--;
        if(i>=j) return 0;
        return j-i+1;
    }
};