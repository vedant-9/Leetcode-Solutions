// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        vector<int> b(a);
        sort(a.rbegin(),a.rend());
        vector<int> ans,vis(k,0);
        for(int i=0;i<b.size();i++) {
            for(int j=0;j<k;j++){
                if(b[i]==a[j] and !vis[j]) {
                    ans.push_back(b[i]);
                    vis[j]=1;
                    break;
                }
            }
        }
        return ans;
    }
};