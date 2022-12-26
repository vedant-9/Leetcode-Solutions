// https://leetcode.com/problems/design-memory-allocator

class Allocator {
public:
    vector<int> arr;
    Allocator(int n) {
        arr.resize(n, 0);
    }
    
    int allocate(int size, int mID) {
        int n = arr.size(), f = 0, start = -1, len = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]==0) len++;
            else len=0;
            if(len==size) {
                f = 1; start = i-len+1; break;
            }
        }
        if(f==1) {
            for(int i=start; i<start+len; i++) {
                arr[i] = mID;
            }
            return start;
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0, n = arr.size();
        for(int i=0; i<n; i++) {
            if(arr[i]==mID) cnt++, arr[i]=0;
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */