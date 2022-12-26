// https://leetcode.com/problems/append-k-integers-with-minimal-sum

class Solution {
public:
    long long minimalKSum(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        long ans=0;
        for(int i=0;i<a.size() and k;i++) {
            long prev = i==0?0:a[i-1];
            long cnt = min((long)k,max((long)0, a[i]-prev-1));
            k-=cnt;
            ans+=(long)(prev+1+prev+cnt)*cnt/2; // [prev+1,prev+cnt]
        }
        if(k>0) ans+=((long)a.back()+1+a.back()+k)*k/2; // [a.back()+1,a.back()+k]
        return ans;
    }
};