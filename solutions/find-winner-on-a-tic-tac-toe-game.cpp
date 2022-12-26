// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        char a[3][3];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j] = '&';
        
        int cnt = 0;
        for(auto v:moves)
        {
            if(cnt%2==0)
                a[v[0]][v[1]] = 'X';
            else
                a[v[0]][v[1]] = 'O';
            cnt++;
        }
        
        char win = '&';
        for(int i=0;i<3;i++)
        {
            if(a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][0]!='&')
            {
                win = a[i][0];
            }
            if(a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[0][i]!='&')
            {
                win = a[0][i];
            }
        }
        if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]!='&')
        {
            win = a[0][0];
        }
        if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]!='&')
        {
            win = a[0][2];
        }
        if(win=='&' && cnt!=9)
            return "Pending";
        if(win=='X')
            return "A";
        if(win=='O')
            return "B";
        return "Draw";
    }
};