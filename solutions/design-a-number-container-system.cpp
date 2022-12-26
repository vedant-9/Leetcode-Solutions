// https://leetcode.com/problems/design-a-number-container-system

class NumberContainers {
public:
    map<int,set<int>> ind;
    map<int,int> val;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(val.find(index)==val.end()) {
            val[index] = number;
            ind[number].insert(index);
            return;
        }
        int prev_val = val[index];
        ind[prev_val].erase(index);
        val[index] = number;
        ind[number].insert(index);
    }
    
    int find(int number) {
        if(ind.find(number)==ind.end() or ind[number].size()==0) return -1;
        return *ind[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */