// https://leetcode.com/problems/kth-distinct-string-in-an-array

class Solution {
public:
    string kthDistinct(vector<string>& s, int k) {
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++) {
            int f=0;
            for(int j=i+1;j<n;j++) {
                if(s[i]==s[j] and s[i]!="") {
                    s[j]=""; f=1;
                }
            }
            if(f==0 and s[i]!="") 
                cnt++;
            if(cnt==k)
                return s[i];
            s[i]="";
        }
        return "";
    }
};