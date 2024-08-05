class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<map<int, int>> mp(n);
        for(auto x: pick) {
            mp[x[0]][x[1]]++;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(auto it: mp[i]) {
                if(it.second > i) 
                    flag = true;
            }
            if(flag == true) ans++;
        }
        return ans;
    }
};
