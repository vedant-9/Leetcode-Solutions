// https://leetcode.com/problems/longest-uploaded-prefix

class LUPrefix {
public:
    vector<int> vis;
    int l;
    LUPrefix(int n) {
        l = 1;
        vis.resize(100005,0);
    }
    
    void upload(int x) {
        vis[x] = 1;
        while(vis[l]) l++;
    }
    
    int longest() {
        return l-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */