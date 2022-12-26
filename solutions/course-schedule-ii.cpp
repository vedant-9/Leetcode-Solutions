// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& arr) 
    {
        vector<int>adj[nc+1];
        int inc[nc+1];
        memset(inc,0,sizeof(inc));
        for(int i=0;i<arr.size();i++) 
        {
            adj[arr[i][1]].push_back(arr[i][0]);
            inc[arr[i][0]]++;
        }
        queue<int>que;
        for(int i=0;i<nc;i++)
        {
            if(inc[i]==0)
                que.push(i);
        }
        vector<int> ans;
        while(!que.empty())
        {
            int tmp = que.front();
            ans.push_back(tmp);
            que.pop();
            
            for(int i=0;i<adj[tmp].size();i++)
            {
                inc[adj[tmp][i]]--;
                if(inc[adj[tmp][i]]==0) que.push(adj[tmp][i]);
            }
        }
        int f = 0;
        for(int i=0;i<nc;i++)
        {
            if(inc[i]!=0) 
            {
                f=1;
                break;
            }
        }
        if(f==1)
            return {};
        return ans;
    }
};