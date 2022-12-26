// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

typedef long long ll;
class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        ll sum = 0, n = a.size();
        for(auto x:a) sum+=x;
        if(sum<k) return 0;
        
        ll low = 1, high = 1e18, ans = 1e18;
        while(low <= high) {
            ll mid = low+(high-low)/2;
            ll f=0;
            for(auto x:a) f+=(x/mid);
            if(f<k) high=mid-1;
            else low=mid+1,ans=mid;
        }
        
        return ans;
    }
};