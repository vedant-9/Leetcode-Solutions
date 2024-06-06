class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false; 
        
        multiset<int> ms;
        for(auto x: hand) ms.insert(x);
        
        while(!ms.empty()) {
            int c = 1;
            int prev = *ms.begin(); 
            ms.erase(ms.begin());
            prev++;
            while(c < groupSize) {
                auto it = ms.find(prev);
                if(it == ms.end()) return false;
                ms.erase(it);
                prev++;
                c++;
            }
        }
        
        return true;
    }
};
