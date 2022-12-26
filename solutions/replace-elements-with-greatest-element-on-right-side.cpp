// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& a)
    {
        int n = a.size();
        int mx = -1, t;
        for(int i=n-1;i>=0;i--)
            t = a[i], a[i] = mx, mx = max(mx,t);
        return a;
    }
};