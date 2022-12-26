// https://leetcode.com/problems/meeting-rooms-iii

typedef long long ll;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end(), [](const vector<int> &x, const vector<int> &y){
            return x[0]<y[0]; 
        });
        
        // {endTime, room_no}
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> busyRooms;
        
        vector<ll> roomFreq(n, 0);
        
        // room_no
        priority_queue<ll, vector<ll>, greater<ll>> unusedRooms;
        
        for(ll i=0; i<n; i++) {
            unusedRooms.push(i);
        }
        
        for(auto meet: meetings) {
            ll startTime = meet[0], endTime = meet[1];
            
            // finish all meetings which has endTime less than current meet startTime
            while(!busyRooms.empty() and busyRooms.top().first <= startTime) {
                ll roomNo = busyRooms.top().second;
                busyRooms.pop();
                unusedRooms.push(roomNo);
            }
            
            // Assign current meet into some room
            if(!unusedRooms.empty()) {
                // look for unused room 
                ll roomNo = unusedRooms.top();
                unusedRooms.pop();
                
                roomFreq[roomNo]++;
                
                busyRooms.push({endTime, roomNo});
            } else {
                // find the busy room which has nearest endTime to our startTime
                auto cur = busyRooms.top();
                busyRooms.pop();
                
                ll nearEndTime = cur.first;
                ll roomNo = cur.second; 
                
                roomFreq[roomNo]++;
                
                ll newEndTime = endTime-startTime+nearEndTime;
                
                busyRooms.push({newEndTime, roomNo});
            }
        }
        
        ll maxIndex = 0;
        for(ll i=1; i<n; i++) {
            if(roomFreq[maxIndex] < roomFreq[i]) {
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
};