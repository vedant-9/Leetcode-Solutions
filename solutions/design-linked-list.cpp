// https://leetcode.com/problems/design-linked-list

class MyLinkedList {
public:
    deque<int> a;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        return (index>=0 && index<a.size())? a[index]: -1;
    }
    
    void addAtHead(int val) {
        a.push_front(val);
    }
    
    void addAtTail(int val) {
        a.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>=0 && index<=a.size())
            a.insert(a.begin()+index,val);
    }
    
    void deleteAtIndex(int index) {
        if(index>=0 && index<a.size())
            a.erase(a.begin()+index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */