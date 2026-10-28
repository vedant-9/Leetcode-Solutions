class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // TC - O(n*m)    SC - O(1)
        // string res = "";
        // for (int i = 0; i < strs[0].size(); i++) {
        //     char ch = strs[0][i];
        //     for (auto s : strs) {
        //         if (i >= s.size() or s[i] != ch)
        //             return res;
        //     }
        //     res += ch;
        // }
        // return res;

        // TC - O(n*m*logn)    SC - O(m)
        string res = "";
        sort(strs.begin(), strs.end());
        string firstStr = strs[0];
        string lastStr = strs[strs.size() - 1];
        for(int i = 0; i < strs[0].size(); i++) {
            if(firstStr[i] != lastStr[i]) break;
            res += firstStr[i];
        }
        return res;
    }
};
