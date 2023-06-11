class Solution {
public:
    int findNonMinOrMax(vector<int>& a) {
        sort(a.begin(), a.end());
        int i = 0, n = a.size();
        while(i < n and a[0] == a[i]) i++;
        while(i < n and a[i] == a[n-1]) i++;
        if(i < n) return a[i];
        return -1;
    }
};
