// https://leetcode.com/problems/smallest-value-of-the-rearranged-number

class Solution {
public:
    long long smallestNumber(long long n) {
        long long cnt[10] = {0};
        long long temp = abs(n);
        while(temp) {
            cnt[temp%10]++;
            temp/=10;
        }
        
        long long ans = 0;
        if(n<0) {
            for(int i=9;i>=0;i--) {
                while(cnt[i]--) 
                    ans=ans*10+i;
            }
            ans=-ans;
        } else {
            if(cnt[0]) {
                for(int i=1;i<=9;i++) {
                    if(cnt[i]) {
                        ans=i;
                        cnt[i]--;
                        break;
                    }
                }
            }
            for(int i=0;i<=9;i++) {
                while(cnt[i]--) 
                    ans=ans*10+i;
            }
        }
        return ans;
    }
};