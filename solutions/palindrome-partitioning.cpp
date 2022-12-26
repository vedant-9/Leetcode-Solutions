// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) 
                return false;
        }
        return true;
    }
    
    void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &ans) {
        int n = s.size();
        if(index == n) {
            ans.push_back(path);
            return;
        }
        for(int i=index; i<n; i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(0, s, path, ans);
        return ans;
    }
};