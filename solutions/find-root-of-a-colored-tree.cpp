class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        // R -> B -> W -> R only accepted
        // build directional edge based on this
        int n = colors.size();
        vector<int> indeg(n, 0), outdeg(n,0);
        for(auto e:edges) {
            if(colors[e[0]] == colors[e[1]]) return -1;
            if(colors[e[0]] == 'B') {
                if(colors[e[1]] == 'W') indeg[e[1]]++,outdeg[e[0]]++;
                else indeg[e[0]]++,outdeg[e[1]]++;
            } else if(colors[e[0]] == 'R') {
                if(colors[e[1]] == 'W') indeg[e[0]]++,outdeg[e[1]]++;
                else indeg[e[1]]++,outdeg[e[0]]++;
            } else {
                if(colors[e[1]] == 'R') indeg[e[1]]++,outdeg[e[0]]++;
                else indeg[e[0]]++,outdeg[e[1]]++;
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(outdeg[i] > 2) return -1;
            if(indeg[i] == 0) {
                if(ans != -1) return -1;
                ans = i;
            } 
        }
        return ans;
    }
};
