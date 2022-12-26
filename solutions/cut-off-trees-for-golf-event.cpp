// https://leetcode.com/problems/cut-off-trees-for-golf-event

class Solution {
public:
    int cutOffTree(vector<vector<int>>& mat) {

        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<long long>>v;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]>1)
                    v.push_back({i,j,mat[i][j]});
            }
        }
        
        // bfs from source to destination
        auto bfs=[&](int st1,int st2,int ds1,int ds2)
        {
            queue<pair<int,int>>q;
            q.push({st1,st2});
            
            int level=0;
            vector<vector<bool>>vis(n+2,vector<bool>(m+2,false));
            vis[st1][st2]=true;
            
            while(q.size())
            {
                int size=q.size();
                for(int i=0;i<size;i++)
                {
                    auto temp=q.front();
                    q.pop();
                    long long x=temp.first;
                    long long y=temp.second;
                    
                    if(x==ds1&&y==ds2)
                        return level;
                    
                    for(auto &it:d)
                    {
                        long long nx=x+it.first;
                        long long ny=y+it.second;
                        
                        if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]>=1&&vis[nx][ny]==false)
                        {
                            q.push({nx,ny});
                            vis[nx][ny]=true;
                        }
                    }
                }
                level++;
            }
            return -1;
        };
        
        sort(v.begin(),v.end(),[&](auto &v1,auto &v2){return v1[2]<v2[2];});
        
        long long st1=0;
        long long st2=0;
        long long count=0;
        
        for(int i=0;i<v.size();i++)
        {
            long long ds1=v[i][0];
            long long ds2=v[i][1];
            long long step=bfs(st1,st2,ds1,ds2);
            
            if(step<0)
                return -1;
            
            count+=step;
            st1=ds1;
            st2=ds2;
        }
        return count;
    }
};