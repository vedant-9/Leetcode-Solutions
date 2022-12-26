// https://leetcode.com/problems/split-array-into-consecutive-subsequences

class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int,int> cnt, tails;
        for(int x : a) 
            cnt[x]++;
        
        for(int &x : a){
            if(!cnt[x]) 
                continue;
            cnt[x]--;
            
            // two options for each x
            // either get included in prev subseq ending at x-1
            // or enter into new subseq but having x+1 and x+2 remaining
            if(tails[x-1] > 0){
                tails[x-1]--;
                tails[x]++;
            }
            else if(cnt[x+1] && cnt[x+2]){
                cnt[x+1]--;
                cnt[x+2]--;
                tails[x+2]++;
            }
            else 
                return false;
        }
        return true;
    }
};