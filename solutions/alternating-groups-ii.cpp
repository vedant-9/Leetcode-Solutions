class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, cnt = 1;
        for(int i = 0; i < n + k - 2; i++) {
            if(colors[i%n] != colors[(i+1)%n]) cnt++;
            else cnt = 1;
            if(cnt >= k) ans++;
        }
        return ans;
    }
};
