// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) 
    {   
        unordered_set<int> uset(a.begin(),a.end());
        int max = *max_element(a.begin(),a.end());
        int min = *min_element(a.begin(),a.end());
        int diff = (max-min)/(a.size()-1);
        for(int i=1;i<a.size();i++){
            if(!uset.count(min + i * diff)){
                return false;
            }
        }
        return true;
    }
};