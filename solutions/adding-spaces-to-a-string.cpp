// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& a) {
        string res="";
        int j=0;
        if(a[0]==0) res+=" ",j++;
        for(int i=0;i<s.size();i++) {
            res+=s[i];
            if(j<a.size() and i==a[j]-1) res+=" ",j++;
        }
        return res;
    }
};