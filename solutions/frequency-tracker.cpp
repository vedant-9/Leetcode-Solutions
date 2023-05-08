class FrequencyTracker {
public:
    map<int, int> mp, mp1;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        mp[number]++;
        mp1[mp[number]]++;
        mp1[mp[number]-1]--;
    }
    
    void deleteOne(int number) {
        if(mp[number] <= 0) return;
        mp[number]--;
        mp1[mp[number]+1]--;
        mp1[mp[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return mp1[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
