// https://leetcode.com/problems/maximum-points-in-an-archery-competition

class Solution {
public:
    int n,mxsc=0;
    vector<int> a,ans;
    
    void rec(int i, int rem, vector<int> &b) {
        if(i==12 or rem==0) {
            if(rem!=0) b[11]+=rem;
            int sc=0; 
            for(int i=0;i<12;i++) {
                if(a[i]<b[i]) sc+=i;
            }
            if(sc>mxsc) mxsc=sc,ans=b;
            b[11]-=rem;
            return;
        } 
        // lose
        rec(i+1,rem,b);
        // if win
        if(rem>a[i]) {
            b[i]=a[i]+1;
            rec(i+1,rem-a[i]-1,b);
        }
        b[i]=0;
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& a) {
        this->n=n; this->a=a;
        vector<int> b(12,0);
        rec(0,n,b);
        return ans;
    }
};