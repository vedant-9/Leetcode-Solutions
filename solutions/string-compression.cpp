// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& a) {
        int n = a.size();
        int i = 0, j = 0;
        while(i<n) {
            char ch = a[i];
            int c=0;
            while(i<n and a[i]==ch) i++,c++;
            a[j]=ch; j++;
            string s = to_string(c);
            int k=0;
            while(c!=1 and k<s.size()) {
                a[j++]=s[k++];
            }
        }
        return j;
    }
};