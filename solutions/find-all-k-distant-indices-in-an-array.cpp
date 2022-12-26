// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) {
        vector<int> ans;
        int n = a.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(abs(i-j)<=k and a[j]==key) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};