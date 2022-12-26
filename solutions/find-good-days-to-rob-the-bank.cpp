// https://leetcode.com/problems/find-good-days-to-rob-the-bank

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int t) {
        int n=a.size();
        int k=2*t+1;
        if(k>n) return {};
        int left[n],right[n]; right[n-1]=0; left[0]=0;
        for(int i=n-2;i>=0;i--) {
            if(a[i]<=a[i+1]) right[i]=right[i+1]+1;
            else right[i]=0;
        }
        for(int i=1;i<n;i++) {
            if(a[i]<=a[i-1]) left[i]=left[i-1]+1;
            else left[i]=0;
        }
        vector<int> ans;
        for(int i=t;i+t<n;i++) {
            if(left[i]>=t and right[i]>=t) ans.push_back(i);
        }
        return ans;
    }
};