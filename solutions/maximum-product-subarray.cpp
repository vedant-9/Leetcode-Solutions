// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& a) 
    {
        int n = a.size();
        
        int product = 1, mx = INT_MIN;
        for(int i = 0; i < n; i++) 
        {
            mx = max(product *= a[i], mx);
            if (a[i] == 0) 
                product = 1;
        }

        product = 1;
        for(int i = n - 1; i >= 0; i--) 
        {
            mx = max(product *= a[i], mx);
            if(a[i] == 0) 
                product = 1;
        }

        return mx;
    }
};