// https://leetcode.com/problems/operations-on-tree

class LockingTree {
public:
    // ith node locked by which user, if -1 it's unlocked
    vector<int> locked;
    
    int n;
    vector<int> parent;
    unordered_map<int, vector<int>> childs;
    
    LockingTree(vector<int>& arr) {
        n = arr.size();
        parent = arr;
        locked = vector<int> (n, -1);
        
        for(int i = 1; i < n; ++i) {
            childs[arr[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num] != -1) return false;
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(locked[num] == -1) return false;
        if(locked[num] != user) return false;
        locked[num] = -1;
        return true;
    }
    
    bool descendentCheck(int num, int user) {
        queue<int> q;
        q.push(num);
        
        while(q.size()) {
            auto curr = q.front();
            q.pop();
            
            if(locked[curr] != -1) return true;
            
            for(auto& child: childs[curr]) {
                q.push(child);
            }
        }
        
        return false;
    }
    
    bool ancestorCheck(int num, int user) {
        while(num != -1) {
            if(locked[num] != -1) return false;
            num = parent[num];
        }
        
        return true;
    }
    
    void unlockAllChild(int num) {
        queue<int> q;
        q.push(num);
        
        while(q.size()) {
            auto curr = q.front();
            q.pop();
            
            if(locked[curr] != -1) locked[curr] = -1;
            
            for(auto& child: childs[curr]) {
                q.push(child);
            }
        }
    }
    
    bool upgrade(int num, int user) {
        if(locked[num] != -1) return false;
        if(!descendentCheck(num, user)) return false;
        if(!ancestorCheck(num, user)) return false;
        
        // everything is valid, now lock current and unlock all descendants
        unlockAllChild(num);
        locked[num] = user;
        
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */