// https://leetcode.com/problems/frog-jump

class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        unordered_map<int, unordered_set<int>> steps = {{0, {0}}};  
        for (int pos : stones) 
        {
            for (auto it = steps[pos].begin(); it != steps[pos].end(); it++) 
            {  
                // record all future reachable positions
                if (*it - 1) 
                { 
                    steps[pos + *it - 1].insert(*it - 1); 
                }
                steps[pos + *it].insert(*it);
                steps[pos + *it + 1].insert(*it + 1);
            }
        }
        return steps[stones.back()].size(); 
        // check if the last position is reachable    
    }
};