// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& a) 
    {
        int m = a.size();
        int n = a[0].size();
        set<int,greater<int>> sums;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                // max size rhombus it can form
                int msz = min({i,j,m-1-i,n-1-j});
                // cout<<msz<<" ";
                if(msz==0)
                {
                    sums.insert(a[i][j]);
                    continue;
                }
                sums.insert(a[i][j]);
                int len = 0;
                while((i-len-1)>=0 && (i+len+1)<m && (j-len-1)>=0 && (j+len+1)<n )
                {
                    len++;
                    long sum = 0;
                    sum += a[i+len][j];      
                    sum += a[i][j+len];      
                    sum += a[i-len][j];     
                    sum += a[i][j-len];     

                    for(int k=1;k<len;k++)
                    {
                        sum +=a[i+len-k][j+k];
                        sum += a[i-k][j+len-k];
                        sum += a[i-len+k][j-k];
                        sum += a[i+k][j-len+k];        
                    }
                    
                    sums.insert(sum);
                }
            }
        }
        vector<int> ans;
        int cnt = 0;
        for(auto x:sums)
        {
            if(cnt==3)
                break;
            ans.push_back(x);
            cnt++;
        }
        return ans;
    }
};