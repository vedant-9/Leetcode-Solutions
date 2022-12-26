// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair

class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int t) 
    {
        // min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        // arrival time of target friend
        int tf_at = a[t][0];   
        
        // sort according to arrival times
        sort(a.begin(), a.end());
        
        // free chair index
        int n=0;   
        
        set<int> s;
        for(auto v: a)
        {
            int at = v[0];                            
            int lt = v[1];  
            
            // cs for current person need chair to sit 
            int cs;    
            
            // remove those whose lt <= at
            // so insert into set their chair indices free
            while(!q.empty() && q.top().first<=at)
            {   
                s.insert(q.top().second);
                q.pop();
            }
            
            // if set has free chair indices
            if(s.size()!=0)
            {         
                // take smallest one
                cs=*(s.begin());
                s.erase(s.begin());
            }
            else
            {
                // assign free chair n and do n++
                cs=n;
                n++;
            }
            
            // push leaving time and current chair to be freed after
            q.push({lt, cs}); 
            
            // Distinct arrival times so compare
            if(tf_at==at)
            {               
                return cs;
            }
        }
        return 0;
    }
};