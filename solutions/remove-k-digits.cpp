// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        // remove the first peak element k times
        // O(k*n)
        while (k > 0) 
        {
            int n = num.size();
            int i = 0;
            while (i+1<n && num[i]<=num[i+1]) 
                i++;
            num.erase(i, 1);
            k--;
        }
        
        // trim leading zeros
        int s = 0;
        while (s<(int)num.size()-1 && num[s]=='0')  
            s++;
        num.erase(0, s);
        
        return num=="" ? "0" : num;
    }
};