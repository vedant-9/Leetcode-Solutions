// https://leetcode.com/problems/destroying-asteroids

class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        
        long long t = m;
        for(int i=0;i<n;i++) {
            if(a[i]>t) {
                return false;
            }
            t+=a[i];
        }
        return true;
    }
};