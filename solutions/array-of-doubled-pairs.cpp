// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& a) 
    {
        unordered_map<int, int> c;
        for (int x : a) c[x]++;
        
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : keys) 
        {
            if (c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        return true;
    }
};