// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& a, int tar) 
    {
        int n = a.size();
        
        sort(a.begin(),a.end());
        
        int ans = 100000;
        
        for(int i=0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            
            while(j<k)
            {
                int sum = a[i]+a[j]+a[k];
                if(sum==tar)
                {
                    return sum;
                }
                if(abs(sum-tar)<abs(ans-tar))
                {
                    ans = sum;
                }
                if(sum<tar)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};