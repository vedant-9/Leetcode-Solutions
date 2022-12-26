// https://leetcode.com/problems/maximum-compatibility-score-sum

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
    {
        int m = students.size(),n = students[0].size();
        
        vector<int> t;
        for(int i=0;i<m;i++)
            t.push_back(i);
        
        int mx = 0;
        do
        {
            int sum = 0;
            for(int i=0,j=0;i<m;i++,j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(students[i][k]==mentors[t[j]][k])
                        sum++;
                }
            }
            mx = max(mx,sum);
        }while(next_permutation(t.begin(),t.end()));
        
        return mx;
    }
};