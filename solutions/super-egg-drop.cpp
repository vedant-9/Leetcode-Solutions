// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    vector<vector<int>> dp;
    int find(int k, int n)
    {
        // 0 or 1 floor remaining
        if(n==0 || n==1) return n;
        
        // only 1 egg remaining
        if(k==1) return n;
        
        // check dp state
        if(dp[k][n]!=-1)
            return dp[k][n];
        
        // break or not break for each floor
        // take worst of both
        int ans=1000000;
        
        // binary search
        int l = 1, h = n, temp = 0;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int left = find(k-1,mid-1);
            int right = find(k,n-mid);
            temp=1+max(left,right);  
            
            if(left<right)
            {                
                l=mid+1;                     
            }
            else                            
            {    
                h=mid-1;
            }
            ans=min(ans,temp);
        }
        return dp[k][n] = ans;
    }
    
    int superEggDrop(int k, int n) 
    {
        dp.resize(k+1);
        for(auto &v:dp)
        {
            v.resize(n+1);
        }
        
        for(auto &v:dp)
        {
            for(auto &x:v)
                x  = -1;
        }
        
        return find(k,n);
    }
};