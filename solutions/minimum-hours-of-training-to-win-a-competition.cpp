// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition

class Solution {
public:
    int minNumberOfHours(int en, int exp, vector<int>& a, vector<int>& b) {
        int ans = 0, n = a.size();
        int sum = 0;
        for(int i=0;i<n;i++) 
            sum += a[i];
        int x = sum-en+1;
        if(en<=sum) en += x, ans += x;
        for(int i=0;i<n;i++) {
            if(exp>b[i]) exp+=b[i];
            else {
                ans += (b[i]-exp+1);
                exp += (b[i]-exp+1+b[i]);
            }
        }
        return ans;
    }
};