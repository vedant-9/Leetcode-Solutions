// https://leetcode.com/problems/stamping-the-sequence

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<int> ans;
        while(1) {
            int ff=1;
            for(int i=0; i<n-m+1; i++) {
                string t = target.substr(i,m);
                
                if(count(t.begin(),t.end(),'?')==m) 
                    continue;
                
                int f=0;
                for(int j=0; j<m; j++) {
                    if(t[j]!=stamp[j] and t[j]!='?') {
                        f=1; break;
                    }
                }
                if(f==0) {
                    for(int j=0; j<m; j++)
                        target[i+j] = '?';
                    ans.push_back(i);
                    ff=0;
                    break;
                }
            }
            if(ff)
                break;
        }
        if(count(target.begin(),target.end(),'?')!=n)
            ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};