// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        int dp[n];
        
        if(s[0]=='1')
            dp[0]=1;
        else dp[0]=0;
        
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                dp[i]=dp[i-1]+2;
                dp[i]= min(dp[i], i+1);
            }else{
                dp[i] = dp[i-1];
            }
        }
        
        int ans = dp[n-1];
        for(int i=n-1;i>0;i--)
            ans = min(ans, n-i + dp[i-1]);
        
        ans = min(ans, n);
        return ans;
    }
};