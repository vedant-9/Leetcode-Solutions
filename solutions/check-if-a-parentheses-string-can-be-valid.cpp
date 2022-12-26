// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(), f = 0;
        
        if(n%2!=0) return false;
        
        int cnt = 0, uc = 0;
        for(int i=0;i<n;i++) {
            if(locked[i]=='1' and s[i]==')') cnt--;
            else cnt++;
            
            if(cnt<0) return false;
            if(locked[i]=='0') uc++;
        }
        if(uc>=(cnt/2)) f++;
        
        cnt=0, uc=0;
        for(int i=n-1;i>=0;i--) {
            if(locked[i]=='1' and s[i]=='(') cnt--;
            else cnt++;
            
            if(cnt<0) return false;
            if(locked[i]=='0') uc++;
        }
        if(uc>=(cnt/2)) f++;
        
        return (f==2);
    }
};