class Solution {
public:
    int ans = 0;
    int dfs(int i, vector<int> &cost) {
        if(i >= cost.size()) return 0;
        int lvalue = dfs(2*i+1, cost);
        int rvalue = dfs(2*i+2, cost);
        ans += abs(rvalue-lvalue);
        return max(lvalue, rvalue) + cost[i];
    } 
    
    int minIncrements(int n, vector<int> &cost) {
        dfs(0, cost);
        return ans;
    }
};
