// https://leetcode.com/problems/design-bitset

class Bitset {
public:
    vector<int> a;
    int cnt1,fl;
    Bitset(int size) {
        a.resize(size);
        cnt1=0;
        fl=0;
    }
    
    void fix(int idx) {
        if(fl%2==0) {
            if(a[idx]!=1) cnt1++;
            a[idx]=1;
        } else {
            if(a[idx]!=0) cnt1--;
            a[idx]=0;
        }
    }
    
    void unfix(int idx) {
        if(fl%2!=0) {
            if(a[idx]!=1) cnt1++;
            a[idx]=1;
        } else {
            if(a[idx]!=0) cnt1--;
            a[idx]=0;
        }
    }
    
    void flip() {
        fl++;
    }
    
    bool all() {
        if((fl%2==0 and cnt1==a.size()) or (fl%2!=0 and cnt1==0)) return 1;
        return 0;
    }
    
    bool one() {
        if((fl%2==0 and cnt1!=0) or (fl%2!=0 and cnt1!=a.size())) return 1;
        return 0;
    }
    
    int count() {
        if(fl%2==0) return cnt1;
        return a.size()-cnt1;
    }
    
    string toString() {
        string res = "";
        if(fl%2!=0) {
            for(int i=0;i<a.size();i++) {
                res+=(char)(1-a[i]+'0');
            }
        } else {
            for(int i=0;i<a.size();i++) {
                res+=(char)(a[i]+'0');
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */