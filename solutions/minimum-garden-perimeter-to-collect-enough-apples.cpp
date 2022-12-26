// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples

class Solution {
public:
    long long minimumPerimeter(long long neededApples) 
    {
        long long sum = 0;
        long long ans = 0;
        long long cnt = 0,x=1;
        while(sum<neededApples)
        {
            cnt = x*x;
            sum += 12*(cnt);
            // cout<<sum<<" ";
            x++;
            ans++;
        }
        // cout<<ans<<endl;
        return ans*8;
    }
};