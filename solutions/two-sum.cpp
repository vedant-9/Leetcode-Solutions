// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int tar) 
    {
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (int i = 0; i < a.size(); i++) 
        {
            int numberToFind = tar - a[i];

            // if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) 
            {
                result.push_back(hash[numberToFind]);
                result.push_back(i);			
                return result;
            }

            //number was not found. Put it in the map.
            hash[a[i]] = i;
        }
        return result;
    }
};