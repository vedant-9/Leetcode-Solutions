// https://leetcode.com/problems/largest-multiple-of-three

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        
        // remainder - 1/2 then 1st small/2nd small
        int rem1_1 = 10, rem1_2 = 10;
        int rem2_1 = 10, rem2_2 = 10;
        
        int sum = 0;
        for(auto d: digits) {
            sum += d;
            if(d%3 == 1) {
                if(rem1_1 >= d) rem1_2 = rem1_1, rem1_1 = d;
                else if(rem1_2 > d) rem1_2 = d;                     
            } else if(d%3 == 2) {
                if(rem2_1 >= d) rem2_2 = rem2_1, rem2_1 = d;
                else if(rem2_2 > d) rem2_2 = d;
            }
        }
        
        // rem = 1    -> 1 of 1 or 2 of 2
        // rem = 2    -> 1 of 2 or 2 of 1
        if(sum%3 == 1) {
            if(rem1_1 != 10) {
                auto it = find(digits.begin(), digits.end(), rem1_1);
                digits.erase(it);
            } else {
                auto it = find(digits.begin(), digits.end(), rem2_1);
                digits.erase(it);
                it = find(digits.begin(), digits.end(), rem2_2);
                digits.erase(it);
            }
        } else if(sum%3 == 2) {
            if(rem2_1 != 10) {
                auto it = find(digits.begin(), digits.end(), rem2_1);
                digits.erase(it);
            } else {
                auto it = find(digits.begin(), digits.end(), rem1_1);
                digits.erase(it);
                it = find(digits.begin(), digits.end(), rem1_2);
                digits.erase(it);
            }
        }
        
        string res;
        for(auto d: digits) {
            res += to_string(d);
        }
        sort(res.rbegin(),res.rend());
        // handle leading zeros
        if(res!="" and res[0]=='0') res="0"; 
        return res;
    }
};