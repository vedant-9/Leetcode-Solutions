// https://leetcode.com/problems/stickers-to-spell-word

class Solution {
public:
    unordered_map<string, int> dp;
    int rec(vector<vector<int>> &freqs, string cur) {
        
        if(cur == "") return 0;
        
        if(dp.find(cur) != dp.end()) return dp[cur];
            
        vector<int> need(26, 0);
        for(auto &ch: cur) {
            need[ch-'a']++;
        }
        
        int ans = 1e8;
        for(auto &freq: freqs) {
            // check if we should take it
            bool canTake = false;
            for(int i=0; i<26; i++) {
                if(need[i]>0 and freq[i]>0) {
                    canTake = true;
                }
            }
            if(canTake) {
                string newcur = "";
                for(int i=0; i<26; i++) {
                    int fr = max(0, need[i]-freq[i]);
                    newcur += string(fr, 'a'+i);
                }
                
                int res = rec(freqs, newcur);
                ans = min(ans, res + 1);
            }
        }
        
        return dp[cur] = ans;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        
        int n = stickers.size();
        
        vector<vector<int>> freqs(n, vector<int>(26, 0));
        for(int i=0; i<n; i++) {
            for(auto &ch: stickers[i]) {
                freqs[i][ch-'a']++;
            }
        }
        
        sort(target.begin(), target.end());
        int ans = rec(freqs, target);
        if(ans >= 1e8) 
            ans = -1;
        
        return ans;
    }
};