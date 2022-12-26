// https://leetcode.com/problems/calculate-digit-sum-of-a-string

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k) {
            string t = "";
            int i = 0;
            while(i<s.size()) {
                int c=0,sum=0;
                while(i<s.size() and c<k) sum+=(s[i]-'0'),i++,c++;
                t+=to_string(sum);
            } 
            // cout<<t<<endl;
            s=t;
        }
        return s;
    }
};