// https://leetcode.com/problems/number-of-arithmetic-triplets

class Solution {
public:
    int arithmeticTriplets(vector<int>& a, int d) {
        int n = a.size();
        sort(a.begin(),a.end());
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(a[j]-a[i]==d and a[k]-a[j]==d) ans++;
                }
            }
        }
        return ans;
    }
};