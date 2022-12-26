// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& a) 
    {
        priority_queue<int,vector<int>> q;
        
        for(auto x:a)
            q.push(x);
        
        while(q.size()>=2)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            
            if(x==y)
                continue;
            else
                q.push(y-x);
        }
        if(q.empty())
            return 0;
        
        return q.top();
    }
};