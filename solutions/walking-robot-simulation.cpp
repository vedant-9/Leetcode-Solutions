// https://leetcode.com/problems/walking-robot-simulation

class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) 
    {
        // directions - n e s w
        // turn right dir++ else dir--
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        // set of obstacles
        set<string> s;
        for(auto o:obs)
        {
            s.insert(to_string(o[0])+" "+to_string(o[1]));
        }
        
        int mx = 0,d = 0, x = 0, y = 0;
        for(auto c:cmd)
        {
            if(c==-2)
            {
                d = (d+3)%4;
            }
            else if(c==-1)
            {
                d = (d+1)%4;
            }
            else
            {
                int step = 0,f=0;
                while(step<c and s.find(to_string(x+dir[d][0])+" "+to_string(y+dir[d][1]))==s.end())
                {
                    x += dir[d][0];
                    y += dir[d][1];
                    step++;
                }
            }
            mx = max(mx,x*x+y*y);
        }
        return mx;
    }
};