// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
public:
    void rec(int cur, int dig, vector<int> &ans, int k) {
        if(dig==0) {
            ans.push_back(cur); 
            return;
        }
        int prev = cur%10;
        
        if(prev+k<10) 
            rec(cur*10+prev+k, dig-1, ans, k);
        if(prev-k>=0 and k) 
            rec(cur*10+prev-k, dig-1, ans, k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<10; i++) {
            rec(i, n-1, ans, k);
        }
        return ans;
    }
};