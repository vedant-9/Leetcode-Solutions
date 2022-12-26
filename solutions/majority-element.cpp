// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& A) 
    {
        // Moore's Voting Algorithm
        int major=A[0], count = 1;
        for(int i=1; i<A.size();i++)
        {
            if(count==0)
            {
                count++;
                major=A[i];
            }
            else if(major==A[i])
            {
                count++;
            }
            else 
                count--;
            
        }
        return major;
    }
};