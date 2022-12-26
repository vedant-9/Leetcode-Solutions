// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array

class Solution {
public:
    int countPairs(vector<int>& a, int k) {
        int ans=0, n=a.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(a[i]==a[j] and (i*j)%k==0) ans++;
            }
        }
        return ans;
    }
};