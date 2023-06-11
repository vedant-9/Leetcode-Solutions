class SnapshotArray {
public:
    vector<map<int, int>> snaps;
    int cur_snap_id = 0;
    SnapshotArray(int length) {
        snaps.resize(length);
        for(auto &mp: snaps) mp[0] = 0;
    }
    
    void set(int index, int val) {
        snaps[index][cur_snap_id] = val;
    }
    
    int snap() {
        cur_snap_id++;
        return cur_snap_id-1;
    }
    
    int get(int index, int snap_id) {
        if(snaps[index].find(snap_id) != snaps[index].end()) return snaps[index][snap_id];
        auto it = --snaps[index].lower_bound(snap_id);
        return it->second;
    }
};
