// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful

class Solution {
public:
    int minDeletion(vector<int>& a) {
        int reversed = 0, res = 0;
        
        for(int i = 0; i < a.size() - 1; i++) {
            if(a[i] == a[i + 1] && reversed == i % 2) {
                reversed ^= 1;// trick
                res++;
            }
        }
        return (a.size() - res) % 2 + res;
    }
};