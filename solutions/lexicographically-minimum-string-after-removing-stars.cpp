class Solution {
public:
    struct cc {
        bool operator()(const pair<char, int> a, const pair<char, int> b) {
            if (a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        int n = s.length();
            
        vector<int> ans(n, 0);
        priority_queue<pair<char, int>, vector<pair<char, int>>, cc> pq;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                auto cur = pq.top(); pq.pop();
                ans[cur.second] = -1;
                ans[i] = -1;
            } else {
                pq.push({s[i], i});
            }
        }
        
        string res = "";
        for(int i = 0; i < n; i++) {
            if(ans[i] != -1) res += s[i]; 
        }
        return res;
    }
};
