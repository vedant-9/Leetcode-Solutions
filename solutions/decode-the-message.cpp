// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string k, string s) {
        map<char,char> mp;
        mp[' ']=' ';
        char ch='a';
        for(auto x:k) {
            if(mp.find(x)!=mp.end()) continue;
            mp[x]=ch;
            ch++;
        }
        string res="";
        for(auto x:s) {
            res+=mp[x];
        }
        return res;
    }
};