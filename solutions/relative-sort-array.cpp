// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) 
    {
        map<int, int> m;
        for (auto i : a) 
            m[i]++;
        
        int pos = 0;
        for (auto j : b) 
        {
            while(m[j]-- > 0) 
                a[pos++] = j;
        }
        for (auto it : m) 
        {
            while(it.second-- > 0) 
                a[pos++] = it.first;
        }
        return a;
    }
};