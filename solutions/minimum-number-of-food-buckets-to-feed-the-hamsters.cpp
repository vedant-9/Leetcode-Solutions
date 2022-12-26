// https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters

class Solution {
public:
    int minimumBuckets(string s) {
        int ans=0,n=s.size(),i=0;
        if(s.find("HHH")!=string::npos or s=="H" or s=="HH") return -1;
        while(i<n) {
            if(s[i]=='H') {
                if(i+2<n and s[i+1]=='.' and s[i+2]=='H') ans++,i+=3;
                else if(i+1<n and s[i+1]=='.') ans++,i+=2;
                else if(i-1>=0 and s[i-1]=='.') ans++,i++;
                else {ans=-1; break;}
            }
            else i++;
        }
        return ans;
    }
};