// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int> preXor(n+1, 0);
        for(int i=1; i<=n; i++) {
            preXor[i] = preXor[i-1] ^ arr[i-1];
        }
        
        vector<int> ans;
        for(auto &q: queries) {
            ans.push_back(preXor[q[1]+1] ^ preXor[q[0]]);
        }
        
        return ans;
    }
};