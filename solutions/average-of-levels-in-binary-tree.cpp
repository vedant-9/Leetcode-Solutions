// https://leetcode.com/problems/average-of-levels-in-binary-tree

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        long long sum = 0, cnt = 0;
        while(q.size()>1) {
            auto cur = q.front(); q.pop();
            if(cur==NULL) {
                ans.push_back(sum*1.0/cnt);
                sum=0,cnt=0;
                q.push(NULL);
                continue;
            }
            sum+=cur->val;
            cnt++;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        ans.push_back(sum*1.0/cnt);
        return ans;
    }
};