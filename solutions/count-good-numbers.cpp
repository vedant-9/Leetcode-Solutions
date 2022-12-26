// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    #define M 1000000007
    
    int mul(long long a,long long b){a=a%M;b=b%M;return(((a*b)%M)+M)%M;}
    int be(long long a, long long b){long long t=1; while(b>0){if(b&1) t=(t*a)%M; b/=2; a=(a*a)%M;}return t%M;}
    
    int countGoodNumbers(long long n) 
    {
        // binary exponentiation of (20^(n/2)) * 5^n&1
        int ans = be(20,n/2);
        if(n&1)
        {
            ans = mul(ans,5);
        }
        return ans;
    }
};