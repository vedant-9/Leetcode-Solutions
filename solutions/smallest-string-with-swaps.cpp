// https://leetcode.com/problems/smallest-string-with-swaps

class Solution {
public:
    class dsu {
    public:
        vector<int> p,s;
        dsu(int n) {
            p.resize(n); s.resize(n);
            for(int i=0;i<n;i++)
                p[i]=i,s[i]=1;
        }
        int find_set(int x) {
            if(p[x]==x) return x;
            return find_set(p[x]);
        }
        bool same_set(int x,int y) {
            return find_set(x)==find_set(y);
        }
        void union_sets(int x,int y) {
            x=find_set(x); y=find_set(y);
            if(x==y) return;
            if(s[x]<s[y]) swap(x,y);
            p[y]=x; s[x]+=s[y];
        }
    };
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& a) {
        int n=s.size();
        dsu d(n);
        for(auto p:a) {
            d.union_sets(p[0],p[1]);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) {
            mp[d.find_set(i)].push_back(i);
        }
        for(auto &it:mp) {
            auto &v=it.second;
            string t="";
            for(auto x:v) {
                t+=s[x];
            }
            sort(t.begin(),t.end());
            int j=0;
            for(auto x:v) {
                s[x]=t[j++];
            }
        }
        return s;
    }
};