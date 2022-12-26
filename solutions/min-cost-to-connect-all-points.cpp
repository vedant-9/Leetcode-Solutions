// https://leetcode.com/problems/min-cost-to-connect-all-points

#define pii pair<int, int>
#define pb push_back
#define fr first
#define sc second

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
		
        //visited and non-visited sets are used to consider the points int the MST and remaining
		set<pii> vis,unvis;  
        
        //All points in un-visited
        for(int i=0;i<n;i++) unvis.insert({points[i][0],points[i][1]});  

		//Priority queue is having distance as key(from growing MST) and pair<int,int> for coordinates in graph
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> q;

        int ans=0; q.push({0,{points[0][0],points[0][1]}});  
        while(!q.empty() && vis.size()<n)
        {
            pair<int,pii> pi=q.top(); q.pop();  //minimum distance coordinate/vertex from growing ST.
            
            if(vis.find(pi.sc)!=vis.end()) continue; //if already visited (skip)
            
            vis.insert(pi.sc); unvis.erase(pi.sc); //remove from unvis and insert into vis (like boolean marking)

			for(auto itr:unvis)   // now consider only those vertices which have not been visited before
            {
                int dist=abs(pi.sc.fr-itr.fr)+abs(pi.sc.sc-itr.sc);
                q.push({dist,{itr.fr,itr.sc}});
            }
			
            ans=ans+pi.fr;
        }
        return ans;
    }
};