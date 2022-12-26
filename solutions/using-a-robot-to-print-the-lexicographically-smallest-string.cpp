// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        
        vector<int> lastOcc(26, -1);
        for(int i=0; i<n; i++) 
            lastOcc[s[i]-'a'] = i;
        
        string ans;
        stack<char> st;
        for(int i=0; i<n; i++) {
            st.push(s[i]);
            bool notWrite = false;
            while(!st.empty()) {
                for(int j=0; j<st.top()-'a'; j++) {
                    if(i<lastOcc[j]) {
                        notWrite = true;
                        break;
                    }
                }
                if(notWrite) break;
                ans.push_back(st.top()); st.pop();
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top()); st.pop();
        }
        
        return ans;
    }
};