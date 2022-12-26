// https://leetcode.com/problems/maximum-good-people-based-on-statements

class Solution {
public:
    int n,ans=0;
    vector<vector<int>> a;
    void rec(int i, vector<int> &p) {
        if(i==n) {
            int f=0,c=0;
            for(int k=0;k<n;k++) {
                if(p[k]==1) {
                    c++;
                    for(int l=0;l<n;l++) {
                        if(a[k][l]!=2 and a[k][l]!=p[l]) {
                            f=1;
                            break;
                        }
                    }
                }
            }
            if(f==0) ans=max(ans,c);
            return;
        }
        p.push_back(0);
        rec(i+1,p);
        p.pop_back();
        p.push_back(1);
        rec(i+1,p);
        p.pop_back();
    }
    
    int maximumGood(vector<vector<int>>& a) {
        vector<int> p; n=a.size();
        this->a=a;
        rec(0,p);
        return ans;
    }
};