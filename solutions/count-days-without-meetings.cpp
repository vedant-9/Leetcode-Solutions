class Solution {
public:
    int countDays(int days, vector<vector<int>>& a) {
        vector<vector<int>> v;
        
        sort(a.begin(),a.end());
        v.push_back(a[0]);
        
        int j=0;
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0]<=v[j][1])
                v[j][1]=max(a[i][1],v[j][1]);
            else
            {
                v.push_back(a[i]);
                j++;
            }
        }
        
        int cnt = 0;
        for(auto it: v) {
            cnt += (it[1]-it[0]+1);
        }
    
        return days-cnt;    
    }
};
