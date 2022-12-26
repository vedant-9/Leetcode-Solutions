// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
	void rec(int i, int j,vector<vector<char>>& a)
	{
		if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]=='X' || a[i][j]=='q')
			return;
		a[i][j]='q';
		rec(i-1,j,a);
		rec(i+1,j,a);
		rec(i,j-1,a);
		rec(i,j+1,a);
	}


    void solve(vector<vector<char>>& a) 
	{
		for(int i=0;i<a.size();i++)
		{
			for(int j=0;j<a[0].size();j++)
			{
				if((a[i][j]=='O' || a[i][j]=='q') &&(i==0||j==0||i==a.size()-1||j==a[0].size()-1))
				{
					rec(i,j,a);
				}
			}
		}

		for(int i=0;i<a.size();i++)
		{
			for(int j=0;j<a[0].size();j++)
			{
				if(a[i][j]=='q')a[i][j]='O';
				else if(a[i][j]=='O')a[i][j]='X';
			}
		}



    }
};