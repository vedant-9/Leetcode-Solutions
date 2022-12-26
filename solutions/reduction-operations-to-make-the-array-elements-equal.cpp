// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

class Solution {
public:
    int reductionOperations(vector<int>& A) {
        int n = A.size();
        map<int,int> M;
        for(int i=0;i<n;i++)
        {
            M[A[i]]++;
        }
        
        int c = 0;
        int ans = 0;
        for(auto it:M)
        {
            ans += it.second * c;
            c++;
        }
        return ans;
    }
};