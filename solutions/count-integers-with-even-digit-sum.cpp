// https://leetcode.com/problems/count-integers-with-even-digit-sum

class Solution {
public:
    int countEven(int num) {
        int ans=0;
        for(int i=2;i<=num;i++) {
            int sum=0,j=i;
            while(i) {
                sum+=i%10;
                i/=10;
            }
            i=j;
            if(sum%2==0) ans++;
        }
        return ans;
    }
};