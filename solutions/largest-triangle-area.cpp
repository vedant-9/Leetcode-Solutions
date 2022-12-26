// https://leetcode.com/problems/largest-triangle-area

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& a) 
    {
        double mx = -1;
        int n = a.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x1 = a[i][0],y1 = a[i][1], x2 = a[j][0], y2 = a[j][1], x3 = a[k][0], y3 = a[k][1];
                    double area = abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)))/2.0;
                    mx = max(mx,area);
                }
            }
        }
        return mx;
    }
};