// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) 
    {
        vector<vector<int>> res;
        sort(A.begin(), A.end());
        
        int n = A.size();
        for (int i = 0; i < n; i++) 
        {
            int target = -A[i];
            
            int front = i + 1;
            int back = n - 1;

            if(target < 0)
            {
                break;
            }
            
            
            while (front < back) 
            {

                int sum = A[front] + A[back];

                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else 
                {
                    vector<int> triplet = {A[i], A[front], A[back]};
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && A[front] == triplet[1]) front++;
                    
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && A[back] == triplet[2]) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < n && A[i + 1] == A[i]) 
                i++;
        }
        return res;
    
    }
};