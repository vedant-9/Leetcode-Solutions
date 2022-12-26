// https://leetcode.com/problems/k-divisible-elements-subarrays

class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        int n = a.size();
        vector<int> div(n,0);
        for(int i=0;i<n;i++) div[i]=(a[i]%p==0);
        for(int i=1;i<n;i++) div[i]+=div[i-1];
        set<vector<int>> st;
        for(int i=0;i<n;i++) {
            vector<int> t;
            for(int j=i;j<n;j++) {
                t.push_back(a[j]);
                int cnt = div[j];
                if(i!=0) cnt-=div[i-1];
                if(cnt<=k) {
                    st.insert(t);
                }
            }
        }
        return (int)st.size();
    }
};