// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        int n = h.size();
        // use stack for finding 
        // next smaller index at left and right
        int left[n],right[n];
        stack<int> st;

        // for left
        st.push(0);
        left[0] = -1;
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {   
                st.pop();
            }
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }

        // clear stack
        st = stack<int>();

        // for right
        st.push(n-1);
        right[n-1] = n;
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {   
                st.pop();
            }
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }


        long mx = 0;
        for(int i=0;i<n;i++)
        {
            int width = right[i]-left[i]-1;
            int area = h[i]*width;
            if(area>mx)
                mx = area;
        }
        return mx;
    }
};