// https://leetcode.com/problems/remove-stones-to-minimize-the-total

class Solution {
public:
    int minStoneSum(vector<int>& a, int k) 
    {
        priority_queue<int,vector<int>> q;
        for(auto x:a)
            q.push(x);
        
        while(k--)
        {
            auto c = q.top();
            q.pop();
            
            if(c==0)
                break;
            
            q.push(c-c/2);
        }
        
        int ans = 0;
        while(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};