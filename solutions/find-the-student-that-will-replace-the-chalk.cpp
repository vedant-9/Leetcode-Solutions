// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        int n = a.size();
        long long sum = 0;
        for(auto x:a)
            sum += x;
        
        if(k>=sum && k%sum==0)
            return 0;
        
        if(k>sum)
            k = k%sum;
        
        int i = 0;
        while(i<n) {
            if(k<a[i])
                break;
            k -= a[i];
            i++;
        }
        return i;
    }
};