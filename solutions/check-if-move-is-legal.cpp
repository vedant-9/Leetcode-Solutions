// https://leetcode.com/problems/check-if-move-is-legal

class Solution {
public:
    
    bool isvalid(int i, int j)
    {
        return (i>=0 && j>=0 && i<8 && j<8);
    }
    
    bool checkMove(vector<vector<char>>& a, int r, int c, char color) 
    {
        int n = 8;
        
        char opp = (color=='B')?'W':'B';
        
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        
        
        for(auto d:dir)
        {
            // pick every direction
            int x = d.first, y = d.second;
            // cout<<x<<" "<<y<<endl;
            int i = r+x, j = c+y , cnt = 1;
            while(isvalid(i,j) && a[i][j]==opp)
            {
                i += x;
                j += y;
                cnt++;
            }
            if(isvalid(i,j) && a[i][j]==color && cnt!=1)
                cnt++;
            if(isvalid(i,j) && a[i][j]==color && cnt>=3)
            {
                // cout<<i<<" "<<j<<endl;
                return true;
            }
        }
        return false;
    }
};