// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // using bucket sort
        // storing element at its frquency index in bucket vector
        vector<int> res;
        if (!nums.size()) 
            return res;
        
        unordered_map<int, int> cnt;
        for (auto num : nums) 
            cnt[num]++;
        
        
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) 
        {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) 
        {
            for (int j = 0; j < bucket[i].size(); ++j)
            {
                res.push_back(bucket[i][j]);
                if (res.size() == k) 
                    return res;
            }
        }

        return res;
    }
};