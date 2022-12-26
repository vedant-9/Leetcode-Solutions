// https://leetcode.com/problems/most-frequent-subtree-sum

class Solution {
public:
    map<int, int> freq;
    
    int subtreeSum(TreeNode* root) {
        if(!root) return 0;
        int curSum = root->val + subtreeSum(root->left) + subtreeSum(root->right);
        freq[curSum]++;
        return curSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subtreeSum(root);
        vector<int> ans;
        int maxFreq = 0;
        for(auto it: freq) {
            maxFreq = max(maxFreq, it.second);
        }
        for(auto it: freq) {
            if(it.second == maxFreq) 
                ans.push_back(it.first);
        }
        return ans;
    }
};