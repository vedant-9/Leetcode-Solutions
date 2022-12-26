// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        int n=a.size(),ans=0; 
        while(1) {
            for(int i=0;i<n;i++) {
                if(a[i]==0) continue;
                ans++; a[i]--;
                if(i==k and a[i]==0) return ans;
            }
        }
        return ans;
    }
};