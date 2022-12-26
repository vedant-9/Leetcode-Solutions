// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
// O(1) space not including the input and output variables

// The idea is we do a linear pass using the input array itself as a hash to store which numbers have been seen before. We do this by making elements at certain indexes negative
    vector<int> findDuplicates(vector<int>& a) {
        vector<int> res;
        for(auto &x:a) {
            if(a[abs(x)-1]<0) res.push_back(abs(x));
            else a[abs(x)-1] *= -1;
        }
        return res;
    }
};