class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0, n = citations.size();
        for(int i = 0; i < n; i++) {
            if(n-i <= citations[i]) ans = max(ans, n-i);
        }
        return ans;
    }
};
