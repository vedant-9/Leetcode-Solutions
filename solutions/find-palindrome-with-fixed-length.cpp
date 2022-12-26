// https://leetcode.com/problems/find-palindrome-with-fixed-length

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int l) {
        int nl = l/2;
        long long mn = pow(10,(l-1)/2);
        vector<long long> ans;
        for(auto q:queries) {
            string frs = to_string(mn+q-1);
            string pali = frs; 
            reverse(frs.begin(),frs.end());
            if(l&1) pali+=frs.substr(1,frs.size()-1);
            else pali+=frs;
            if(pali.size()==l) ans.push_back(stoll(pali));
            else ans.push_back(-1);
        }
        return ans;
    }
};