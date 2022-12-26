// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& a) {
        int left=1, right=100000;
        while(left<right) {
            int mid=(left+right)/2, sum=0;
            for (int x:a)
                sum+=(x+mid-1)/mid;
            if (sum>n) left=mid+1;
            else right=mid;
        }
        return left;
    }
};