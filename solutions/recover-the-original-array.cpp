// https://leetcode.com/problems/recover-the-original-array

class Solution {
public:
    vector<int> check(vector<int> &a, int k) {
        int n = a.size();
        map<int,int> cnt;
        for(auto x:a) cnt[x]++;
        
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(cnt[a[i]]==0) continue;
            if(cnt[a[i]+k]==0) return {};
            cnt[a[i]]--; cnt[a[i]+k]--;
            ans.push_back(a[i]+k/2);
        }
        return ans;
    }
    
    vector<int> recoverArray(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        
        for(int i=1;i<n;i++) {
            int k=a[i]-a[0];
            if(k and k%2==0) {
                auto v = check(a,k);
                if(!v.empty())
                    return v;
            }
        } 
        return {};
    }
}; 