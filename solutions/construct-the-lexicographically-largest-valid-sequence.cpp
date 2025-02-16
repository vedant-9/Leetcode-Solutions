class Solution {
public:
    vector<int> used;
    bool dfs(vector<int> &ans, int i) {
        if (i == ans.size()) return true; 

        if (ans[i]) return dfs(ans, i + 1);

        for (int j = used.size() - 1; j > 0; j--) { 
            if (used[j]) continue;

            if (j != 1 && (i + j >= ans.size() || ans[i + j])) continue; 

            used[j] = 1; 
            ans[i] = j; 
            if (j != 1) ans[i + j] = j;
            
            if (dfs(ans, i + 1)) return true;

            ans[i] = 0; 
            if (j != 1) ans[i + j] = 0;
            used[j] = 0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1);
        used.assign(n + 1, 0);
        dfs(ans, 0); 
        return ans;
    }
};
