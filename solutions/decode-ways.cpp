// https://leetcode.com/problems/decode-ways

class Solution {
public:
    
    int dp[120];
	
    int rec(int idx,string s)
    {
		if(s[idx]=='0')
			return dp[idx]=0;
		if(idx>=s.length()-1)
			return dp[idx]=1;	
  		if(dp[idx]!=-1)
      		return dp[idx];
		int ans=0;

		ans+=rec(idx+1,s);
		if(idx<s.length()-1)
		{
			string q;
			q+=s[idx];
      		q+=s[idx+1];
          	if("26">=q)
			    ans += rec(idx+2,s);
		}         
    	return dp[idx] = ans;
    }
    
    
    
    int numDecodings(string s) 
	{
    	memset(dp,-1,sizeof(dp));
    	int ans= rec(0,s);    
        return ans;
    }
};