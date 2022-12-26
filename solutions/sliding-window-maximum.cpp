// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) 
    {
        deque <int> dq;
        vector <int> ans;
        
        for (int i = 0; i < k; i++){
            
            while (!dq.empty() && a[dq.back()] <= a[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        ans.push_back(a[dq.front()]);
        
        for (int i = k; i < a.size(); i++){
            int last_pos = i-k+1;
            while (!dq.empty() && dq.front() < last_pos){
                dq.pop_front();
            }
            
            while (!dq.empty() && a[dq.back()] <= a[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            ans.push_back(a[dq.front()]);
        }
        
        return ans;
    }
};