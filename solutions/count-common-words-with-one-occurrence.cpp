// https://leetcode.com/problems/count-common-words-with-one-occurrence

class Solution {
public:
    int countWords(vector<string>& a, vector<string>& b) {
        map<string,int> m1,m2;
        for(auto s:a) m1[s]++;
        for(auto s:b) m2[s]++;
        int ans=0;
        for(auto it:m1) {
            string s=it.first;
            if(it.second==1 and m2.find(s)!=m2.end() and m2[s]==1)
                ans++;
        }
        return ans;
    }
};