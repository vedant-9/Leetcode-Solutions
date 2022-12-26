// https://leetcode.com/problems/removing-minimum-and-maximum-from-array

class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int x=min_element(a.begin(),a.end())-a.begin();
        int y=max_element(a.begin(),a.end())-a.begin();
        if(x>y) swap(x,y);
        int n=a.size();
        return min({y+1,n-x,x+1+n-y});
    }
};