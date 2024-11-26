class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_deg(n);
        for (auto &e : edges)
            in_deg[e[1]]++;
        
        int j = find(in_deg.begin(), in_deg.end(), 0) - in_deg.begin();
        return count(in_deg.begin(), in_deg.end(), 0) == 1 ? j : -1;
    }
};
