class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> vis(10001, 0);
        for(auto x: banned) vis[x] = 1;
        int curSum = 0, ans = 0;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                curSum += i; ans++;
                if(curSum > maxSum) {
                    ans--; break;
                }
            } 
        }
        return ans;
    }
};
