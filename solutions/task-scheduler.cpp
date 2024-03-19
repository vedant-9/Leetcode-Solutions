class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int, int> freq;
        for(auto task: tasks)
            freq[task]++;

        int maxFreq = 0;
        for(auto it: freq)
            maxFreq = max(maxFreq, it.second);

        int ans = (maxFreq-1) * (n+1);
        for(auto it: freq) 
            if(it.second == maxFreq) 
                ans++;

        return max(ans, (int) tasks.size()); 
    }
};
