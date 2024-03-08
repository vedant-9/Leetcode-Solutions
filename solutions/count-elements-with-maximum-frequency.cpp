class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freq;
        for(auto x: nums) freq[x]++;
        int max_freq = 0;
        for(auto it: freq) max_freq = max(max_freq, it.second);
        int count_with_max_freq = 0;
        for(auto it: freq) {
            if(it.second == max_freq) count_with_max_freq += max_freq;
        }
        return count_with_max_freq;
    }
};
