// https://leetcode.com/problems/watering-plants-ii

class Solution {
public:
    int minimumRefill(vector<int>& a, int ca, int cb) {
        int n=a.size();
        int i=0,j=n-1,ans=0,fa=ca,fb=cb;
        while(i<j) {
            if(a[i]>fa) ans++,fa=ca-a[i];
            else fa-=a[i];
            if(a[j]>fb) ans++,fb=cb-a[j];
            else fb-=a[j];
            i++; j--;
        }
        if(i==j) {
            if(fa>=fb) {
                if(a[i]>fa) ans++;
            }
            else {
                if(a[i]>fb) ans++;
            }
        }
        return ans;
    }
};