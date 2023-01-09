class Solution {
public:
    int maximumCount(vector<int>& a) {
        int n = a.size(), pos = 0, neg = 0;
        for(int i=0; i<n; i++) {
            if(a[i]>0) pos++;
            else if(a[i]<0) neg++;
        }
        return max(pos, neg);
    }
};
