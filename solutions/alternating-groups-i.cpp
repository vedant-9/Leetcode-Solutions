class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for(int i = 0; i < n; i++) {
            int j = (i+1)%n, k = (i+2)%n;
            if(colors[i] != colors[j] and colors[j] != colors[k]) ans++;
        }
        return ans;
    }
};
