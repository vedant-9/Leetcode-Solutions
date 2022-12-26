// https://leetcode.com/problems/next-greater-numerically-balanced-number

class Solution {
public:
    int nextBeautifulNumber(int n) {
        if(n==0)
            return 1;
        while(n++) {
            int a[10]={0},x=n,f=0;
            while(x) {
                a[x%10]++;
                x/=10;
            }
            for(int i=0;i<10;i++) {
                if(a[i] and a[i]!=i)
                    f=1;
            }
            if(f==0) 
                return n;
        }
        return 0;
    }
};