// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

#define MOD 1000000007
class Solution{
public:
    unordered_map<int,vector<pair<int,int>>>graph;
    vector<int> count;
    int n;
    
    void djikstra() {
        
        priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq; 
        
        pq.push({0,0});
        
        vector<long long int> times(n,LLONG_MAX);
        times[0]=0;
        count[0]=1;
        
        while(!pq.empty())
        {
            int tu=pq.top().first, u=pq.top().second;
            pq.pop();
            
            if(tu>times[u])
                continue;
            
            for(auto p:graph[u])
            {
                int v = p.first,tv = p.second;
                long long int time = times[u]+tv;
                
                if(time<times[v])
                {
                    times[v]=time;
                    count[v]=count[u];
                    pq.push({times[v],v});
                }
                else if(time==times[v])
                    count[v]=(count[v]+count[u])%MOD;
            }
        }
    }
    int countPaths(int n, vector<vector<int>>& roads)
    {   
        for(auto edge:roads)
        {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        
        this->n = n;
        count.resize(n);
        djikstra();
        
        return count[n-1];
    }
};