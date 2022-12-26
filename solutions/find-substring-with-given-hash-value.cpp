// https://leetcode.com/problems/find-substring-with-given-hash-value

class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hv) {
        // start from reverse sliding window
        // Can't start from front coz modular division can't perform
        
        int n = s.size();
        vector<int> ans;
        
        reverse(s.begin(),s.end());
        
        long i=0,chv=0;
        while(i<k) {
            chv=(chv*p+s[i]-'a'+1)%m;
            i++;
        }       
        // cout<<chv<<endl;
        ans.push_back(chv);    
    
        long pp=1,c=0;
        while(c<k-1) pp=(pp*p)%m,c++;
        
        while(i<n) {
            long val=((s[i-k]-'a'+1)*pp)%m;
            chv=(chv-val+m)%m;
            chv=(chv*p+s[i]-'a'+1)%m;
            ans.push_back(chv);
            i++;
        }
        
        reverse(s.begin(),s.end());
        reverse(ans.begin(),ans.end());
        for(int i=0;i<=n-k;i++) {
            if(ans[i]==hv) return s.substr(i,k);
        }
        
        return "";
    }
};