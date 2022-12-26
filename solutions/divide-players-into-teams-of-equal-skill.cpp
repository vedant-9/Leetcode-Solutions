// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill

class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        
        long long x = a[0]+a[n-1];
        for(int i=1; i<n/2; i++) {
            if(a[i] + a[n-i-1] != x) return -1;
        }
        
        long long ans = 0;
        for(int i=0; i<n/2; i++) {
            ans += ((long long)a[i] * a[n-i-1]);
        }
        return ans;
    }
};