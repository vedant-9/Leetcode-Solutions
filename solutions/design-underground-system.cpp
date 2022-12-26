// https://leetcode.com/problems/design-underground-system

class UndergroundSystem {
    map<pair<string,string>, pair<int,int>> m; //<station1, station2>, <totalTime, occurrences>
    unordered_map<int, pair<string, int>> status; // <id, <checkin station, checkin time>>
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        status[id] = {stationName, t}; // update status of passenger id
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = status[id]; // get checkin station / time of id
        status.erase(id);
        auto& p2 = m[{p.first, stationName}];
        p2.first += t-p.second; // add time used total time of pair <checkin station, checkout station>
        p2.second++; // increment occurrence
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto p = m[{startStation, endStation}];
        return double(p.first)/double(p.second);
    }
};