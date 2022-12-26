// https://leetcode.com/problems/maximum-number-of-robots-within-budget

class Solution {
public:
    int maximumRobots(vector<int>& a, vector<int>& b, long long budget) {
        int mx = 0, n = a.size();
        
        multiset<int> ms;
        long long cur = 0, sum = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            cur += b[j];
            ms.insert(a[j]);
            if(*ms.rbegin()+(j-i+1)*cur <= budget) {
                mx = max(mx, j-i+1); 
                j++;
            } else {
                while(!ms.empty() and *ms.rbegin()+(j-i+1)*cur > budget) {
                    cur -= b[i];
                    ms.erase(ms.lower_bound(a[i]));
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};