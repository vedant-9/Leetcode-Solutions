// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        map<int, int> mp;
        int k = 1;
        for(int i=n-1,j=0; i>=0; i--,j++) {
            if(j%2 == 0) {
                for(int j=0; j<n; j++) {
                    if(board[i][j] != -1) 
                        mp[k] = board[i][j];
                    k++;
                }
            } else {
                for(int j=n-1; j>=0; j--) {
                    if(board[i][j] != -1) 
                        mp[k] = board[i][j];
                    k++;
                }
            }
        }

        queue<int> q;
        q.push(1);
        vector<int> vis(n*n+10, 0);

        int lvl = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front(); q.pop();
                if(cur >= n*n) return lvl;
                vis[cur] = 1;
                for(int i=1; i<=6; i++) {
                    int next = cur+i;
                    if(mp.find(next) != mp.end()) 
                        next = mp[next];
                    if(!vis[next]) 
                        q.push(next);
                }
            }
            lvl++;
        }

        return -1;
    }
};