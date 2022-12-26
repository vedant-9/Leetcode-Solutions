// https://leetcode.com/problems/queries-on-a-permutation-with-key

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) 
    {
        vector<int>v(m+1);
        for(int i=0;i<m;i++)
            v[i+1]=i;
        for(int j=0;j<queries.size();j++)
        {
            int temp=v[queries[j]];
            for(int i=1;i<=m;i++)
                if(v[i]<temp)
                    v[i]++;
            v[queries[j]]=0;
            queries[j]=temp;
        }
        return queries;
    }
};