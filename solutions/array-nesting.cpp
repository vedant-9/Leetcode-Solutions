// https://leetcode.com/problems/array-nesting

class Solution {
public:
    int arrayNesting(vector<int>& a) 
    {
        int maxsize = 0;
        for (int i = 0; i < a.size(); i++) 
        {
            int size = 0;
            for (int k = i; a[k] >= 0; size++) 
            {
                int ak = a[k];
                a[k] = -1; // mark a[k] as visited;
                k = ak;
            }
            maxsize = max(maxsize, size);
        }

        return maxsize;    
    }
};