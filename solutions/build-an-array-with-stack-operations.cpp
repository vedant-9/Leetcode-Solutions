// https://leetcode.com/problems/build-an-array-with-stack-operations

class Solution {
public:
    vector<string> buildArray(vector<int>& a, int n) 
    {   
        vector<string> res;
        string ph = "Push";
        string pp = "Pop";
        int num = 1;
        for(int i=0; i<a.size(); i++) 
        {
            while(num!=a[i]) 
            {
                num++;
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
            num++;
        }
        return res;
    }
};