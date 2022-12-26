// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) 
    {
        set<pair<int, int>> st;
        pair<int, int> p = {0, 0};
        st.insert(p);
        for(const char &ch : path) 
        {
            if(ch == 'N')      p.second += 1;
            else if(ch == 'E') p.first += 1;
            else if(ch == 'W') p.first -= 1;
            else               p.second -= 1;
            
            if(st.find(p) != end(st)) 
                return true;
            st.insert(p);
        }
        return false;
    }
};