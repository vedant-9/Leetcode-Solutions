// https://leetcode.com/problems/k-radius-subarray-averages

class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        int n=a.size(); vector<int> ans(n,-1);
        long long int sum=0,x=2*k+1,i=0;
        for(i=0;i<=2*k and i<n;i++) {
            sum+=a[i];
        }
        if(i==2*k+1 and k<n) ans[k]=sum/x;
        else return ans;
        int j=0,r=k+1;
        for(int i=2*k+1;i<n;i++) {
            sum-=a[j++];
            sum+=a[i];
            ans[r++]=sum/x;
        }
        return ans;
    }
};