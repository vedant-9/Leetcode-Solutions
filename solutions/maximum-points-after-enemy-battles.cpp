class Solution {
public:
    long long maximumPoints(vector<int>& a, int eng) {
        if(eng == 0) return 0;
        sort(a.begin(), a.end());
        long long cur = eng - a[0];
        if(cur < 0) return 0;
        for(int i = 1; i < a.size(); i++) cur += a[i];
        return (long long)cur/a[0]+1;
    }
};
