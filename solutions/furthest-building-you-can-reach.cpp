// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) 
    {
        int n = a.size();
        
        // greedy approach
        // Go by bricks -> smallest difference
        // Go by ladder -> 
        
        priority_queue<int,vector<int>> pq;
        
        int i = 0;
        for(;i<n-1;i++)
        {
            if(a[i]>=a[i+1])
                continue;
            
            int d = a[i+1]-a[i];
            pq.push(d);
            b-=d;
            
            while(b<0 && l && !pq.empty())
            {
                b+=pq.top();
                pq.pop();
                l--;
            }
            
            if(b<0)
                break;
        }
        return i;
    }
};