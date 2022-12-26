// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) 
    {
        int asz = a.size();
        int bsz = b.size();
        
        unordered_map<int,int> mp;
        
        // next greater element code
        // unique elements that's why pushing directly value
        stack<int> st;
        for(int i=bsz-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<b[i])
            {
                st.pop();
            }
            
            if(st.empty())
                mp[b[i]] = -1;
            else
                mp[b[i]] = st.top();
            st.push(b[i]);
        }
        
        vector<int> ans(asz);
        for(int i=0;i<asz;i++)
        {
            ans[i] = mp[a[i]];
        }
        return ans;
    }
};