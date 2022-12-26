// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& a, int k) 
    {
        sort(a.begin(), a.end());
        long i = 0, n = a.size(), ans = 1, sum = 0;
        for (int j = 0; j < n; j++) 
        {
            sum += a[j];
            while ((j - i + 1) * a[j] - sum > k) 
                sum -= a[i++];
            ans = max(ans, j - i + 1);
        }
        return ans;    
    }
};