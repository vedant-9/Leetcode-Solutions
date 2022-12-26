// https://leetcode.com/problems/push-dominoes

class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        
        int right[n];
        int r=0;
        for(int i=0; i<n; i++) {
            if(s[i]=='.') {
                if(r) r++;
            }
            else if(s[i]=='R') r=1;
            else r=0;
            right[i]=r;
        }
        
        // for(auto &x: right) cout<<x<<" ";
        // cout<<endl;
        
        int left[n];
        int l=0;
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='.') {
                if(l) l++;
            } 
            else if(s[i]=='L') l=1;
            else l=0;
            left[i]=l;
        }
        
        // for(auto &x: left) cout<<x<<" ";
        // cout<<endl;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '.') {
                if(left[i]==0 and right[i]==0) continue;
                else if(left[i]==0 and right[i]) s[i]='R';
                else if(right[i]==0 and left[i]) s[i]='L';
                else {
                    if(left[i]<right[i]) s[i]='L';
                    else if(right[i]<left[i]) s[i]='R';
                    // else s[i]='.';
                }
            }
        }
        
        return s;
    }
}; 