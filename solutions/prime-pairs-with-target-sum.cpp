const int maxN=1e6+5;
vector<bool> spf(maxN+1,true);
class Solution {
public:
    
    void sieve() {
        int n=maxN;
        spf[0]=spf[1]=0;
        for (int p=2;p*p<=n;p++) {
            if (spf[p]) {
                for (int i=p*p;i<=n;i+=p)
                    spf[i]=0;
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        sieve();
        vector<vector<int>> ans;
        for(int i = 2; i <= n/2; i++) {
            if(spf[i] and spf[n-i]) {
                vector<int> tmp = {i, n-i};
                ans.push_back(tmp);
            } 
        }
        return ans;
    }
};
