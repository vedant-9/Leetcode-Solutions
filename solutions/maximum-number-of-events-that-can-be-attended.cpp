// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res=0;int day =1;
        int n= events.size();
        sort (events.begin(), events.end());
        priority_queue<int, vector<int>,greater<int>> pq; // pq with min end times
        int i=0; 
        while(i<n || pq.size() ){
           while (pq.size() && pq.top() <day) // cant attend
               pq.pop();
           while((i< n) && (events[i][0]==day)) //all events with starting day
               pq.push(events[i++][1]);
           day++; 
           if(pq.size()) // attend elligible with min end time
            {
                res++;
                pq.pop();
            }
        }
        return res;
    }
};